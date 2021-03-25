#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <sys/time.h>
#include <sys/select.h>

//84.103.70.123 33333

#define MAX_BUFFER_SIZE 16000 // taille du buffer qui me permet de récupérer le contenu du fichier à recevoir bloc par bloc. Vous pouvez changer cette valeur.

//Multiplexage vs concurrent:
/*
	différence au temps de traitement : Ici on écrit au maximum $MAX_BUFFER_SIZE octet dans un fichier.
	Ecriture est un appel système, considéré lent.
	Cependant on ne fait pas d'autres opérations, donc on peut supposer qu'il s'ajit d'un traitement rapide.

	On pourrait donc penser au multiplexage.

	Mais cet appel système est problématique. Que se passe-t-il si le disque est plein? Il y a-t-il un bloquement? etc

	Si on ne veux pas traiter tous ces cas, on peux utiliser un traitemenbt concurrent.
	En effet, la concurrence est aussi adaptée grâce à cet appel systeme.
	On peux ainsi creer un processus par client après chaque accept.
*/


int recvTCP(int socket, char *buffer, size_t length, unsigned int *nbBytesReceved, unsigned int * nbCallRecv){	
	ssize_t received;

	while (length > 0){
		received = recv(socket, buffer, length, 0);

		if(received <= 0){
			return received;
		}
		
		buffer += received;
		length -= received;

		(*nbBytesReceved) += received;
		(*nbCallRecv)++;
	}
	return 1;
}

int main(int argc, char *argv[])
{
	
	if (argc<2){
		printf("Utilisation : %s numero_port\n", argv[0]);
		exit(1);
	}

	int ds = socket(PF_INET, SOCK_STREAM, 0);

	if (ds < 0) {
		perror("Serveur : erreur creation socket");
		exit(1);
	}

	struct sockaddr_in server;
	server.sin_family = AF_INET;
	server.sin_addr.s_addr =INADDR_ANY;
	server.sin_port = htons( (short) atoi (argv[1]));
	
	if(bind(ds, (struct sockaddr *) &server, sizeof(server)) < 0){
		perror("Serveur : erreur bind");
		close(ds);
		exit(1);
	}

	int ecoute = listen(ds, 5);
	if (ecoute < 0){
		perror("Serveur : erreur ecoute");
		close(ds);
		exit(1);
	}

	unsigned int nbTotalOctetsRecus = 0;
	unsigned int nbAppelRecv = 0;
	
	/* boucle pour le traitement itératif des clients */
	while(1){
		printf("Serveur : j'attends la demande d'un client (accept) \n"); 
		
		struct sockaddr_in adc;
		socklen_t lgc = sizeof (struct sockaddr_in);

		int dsc = accept(ds, (struct sockaddr *)& adc, &lgc);
		if (dsc < 0){
			perror("Serveur : erreur accept");
			break;
		}

		int cpid = fork();
		if (cpid < 0) {
			perror("Serveur : erreur fork");
			continue;
		} 
		if (cpid != 0) {
			//pere
			continue;
		}
		//fils

		printf("Serveur : le client %s:%d est connecté\n", inet_ntoa(adc.sin_addr) , ntohs(adc.sin_port));
	
		// je doit recevoir des données me permettant d'obtenur le nom d'un fichier
		int name_size;
		int rcv = recvTCP(dsc, (char*)&name_size, sizeof(name_size), &nbTotalOctetsRecus, &nbAppelRecv);
		if(rcv<0){
			perror("Serveur : erreur receive");
			close(dsc);
			exit(1);
		}
		if(rcv==0){
			printf("Serveur : client deconnecte\n");
			close(dsc);
			exit(1);
		}
		
		char* file_name = malloc(name_size);

		rcv = recvTCP(dsc, file_name, name_size, &nbTotalOctetsRecus, &nbAppelRecv);
		if(rcv<0){
			perror("Serveur : erreur receive:");
			free(file_name);
			close(dsc);
			exit(1);
		}
		if(rcv==0){
			printf("Serveur : client deconnecte\n");
			free(file_name);
			close(dsc);
			exit(1);
		}

		printf("Serveur, je vais recevoir le fichier %s\n", file_name);

		// je construis le chemin vers le fichier à créer.
		char dir[32];
        dir[0] = '\0';
        strcat(dir, "./reception/");
        strcat(dir, inet_ntoa(adc.sin_addr));

        struct stat sb;
        if (stat(dir, &sb) != 0 || !S_ISDIR(sb.st_mode)) {
            if (mkdir(dir, 0777) < 0) {
                perror("Serveur : erreur mkdir");
                close (dsc);
                exit(1);
            }
        }
        
        strcat(dir, "/");
        char str[6];
        sprintf(str, "%d", ntohs(adc.sin_port));
        strcat(dir, str);
        if (stat(dir, &sb) != 0 || !S_ISDIR(sb.st_mode)) {
            if (mkdir(dir, 0777) < 0) {
                perror("Serveur : erreur mkdir");
                close (dsc);
                exit(1);
            }
        }
        

        char* filepath = malloc(name_size + 64); // ./reception/+nom fichier
        filepath[0] = '\0';
        strcat(filepath, "./reception/");
        strcat(filepath, inet_ntoa(adc.sin_addr)); //127.000.000.001 max 15 char
        strcat(filepath, "/");
        strcat(filepath, str); //999999 max 6 char
        strcat(filepath, "/");
        strcat(filepath, file_name);
        free(file_name);

		// j'ouvre le fichier dans lequel je vais écrire
		FILE* file = fopen(filepath, "wb");
		if(file == NULL){  // servez vous de cet exemple pour le traitement des erreurs. 
			perror("Serveur : erreur ouverture fichier: \n");
			free(filepath);
			close (dsc);
			exit(1); // passer au client suivant 
		}
		
		free(filepath); // je n'en ai plus besoin.

		//reception des données me permettant de recevoir correctement le contenu du fichier.
		int file_size;
	
		rcv = recvTCP(dsc, (char*)&file_size, sizeof(file_size), &nbTotalOctetsRecus, &nbAppelRecv);
		if(rcv<0){
			perror("Serveur : erreur receive:");
			close(dsc);
			exit(1);
		}
		if(rcv==0){
			printf("Serveur : client deconnecte\n");
			close(dsc);
			exit(1);
		}
		
		int contentReceived = 0; // Compte le nombre d'octets du fichier reçu

		// je reçois le contenu progressivement 
		while(contentReceived < file_size){
		
			char buffer[MAX_BUFFER_SIZE];
			rcv = recv(dsc, buffer, MAX_BUFFER_SIZE, 0);  // /!\ ici appel
									// direct de recv
									// car recvTCP
									// n'est pas
									// adapté. Pourquoi ? car il n'y a pas forcément MAX_BUFFER_SIZE octet à lire

			if(rcv<0){
				perror("Serveur : erreur receive:");
				break;
			}
			if(rcv==0){
				printf("Serveur : client deconnecte\n");
				break;
			}
			nbTotalOctetsRecus += rcv;
			nbAppelRecv++;
			
			// si pas d'erreurs, j'ai reçu rcv octets. Je dois les écire dans le fichier.
			size_t written = fwrite(buffer, sizeof(char), rcv, file);
			if(written < rcv){
				perror("Serveur : erreur ecriture du fichier \n");
				break; // je sors de la boucle d'écrture/réception.
			}

			contentReceived += rcv;
		}

		// fermeture du fichier à la fin de son écriture ou si erreur s'est produite.
		
		fclose(file);
		printf("Serveur : fin du dialogue avec le client, nombre total d'octets recus : %d,  recus en %d appels a recv \n", nbTotalOctetsRecus, nbAppelRecv);
		close (dsc);
		//je passe au client suivant.
		exit(0);
	}
	
	close (ds); // atteignable si on sort de la boucle infinie.
	printf("Serveur : je termine\n");
}