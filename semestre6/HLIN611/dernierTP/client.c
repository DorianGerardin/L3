#include <stdio.h> 
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdlib.h>
#include<arpa/inet.h>
#include<string.h>
#include <sys/stat.h>
#include "common.c"



#define MAX_BUFFER_SIZE 16000  // taille du buffer temporaire pour la lecture de fichier. Vous pouvez définir une autre valeur.


int main(int argc, char *argv[]) {

  if (argc != 4){
    printf("utilisation : client ip_serveur port_serveur nom_fichier\n");
    exit(0);
  }


  int ds = socket(PF_INET, SOCK_STREAM, 0);

  struct sockaddr_in server;
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = inet_addr(argv[1]);
  server.sin_port = htons((short) atoi(argv[2]));

  int lgAdr = sizeof(struct sockaddr_in);

  int conn = connect(ds, (struct sockaddr *)&server, lgAdr);

  if (conn <0){
    perror ("Client: pb au connect :");
    close (ds); // je libère les ressources avant de terminer.
    exit (1); // je choisi de quitter le programme : la suite dépend
        // de la réussite de l'envoi de la demande de connexion.
  }

  printf("Client : demande de connexion reussie \n");


    // envoyer le nom de fichier (réfléchir aux données à envoyer pour que le nom soit corectement reçu)

  int name_size = strlen(argv[3]) + 1;

  int totalSent = 0;

  int snd = sendData(ds, (char*)&name_size, sizeof(int));
  /* Traiter TOUTES les valeurs de retour (voir le cours ou la documentation). */
   if (snd < 0) {
    //printf("Client : Erreur lors du send \n");
    perror("Client : Erreur lors du send \n");
    close(ds);
    exit(1);
   }
   if (snd == 0) {
    perror("Client : Serveur déconnecté \n");
    close(ds);
    exit(1);
   }

   printf("Client: je viens d'envoyer la taille du nom du fichier : %d\n", name_size);

   totalSent += snd;

  snd = sendData(ds, argv[3], name_size);

  if (snd < 0) {
    //printf("Client : Erreur lors du send \n");
    perror("Client : Erreur lors du send \n");
    close(ds);
    exit(1);
   }
   if (snd == 0) {
    perror("Client : Serveur déconnecté \n");
    close(ds);
    exit(1);
   }

  printf("Client: je viens d'envoyer le nom du fichier : %s\n", argv[3]);
   
    // je construis le nom complet (chemin) du fichier que je dois lire
  char* filepath = malloc(strlen(argv[3]) + 16); // ./emission/+nom fichier +\0
  filepath[0] = '\0';
  strcat(filepath, "./emission/");
  strcat(filepath, argv[3]);

  printf("Client: je vais envoyer le fichier %s\n", filepath);

  // je récupère la taille du fichier. Pourquoi ?
  struct stat attributes;
  if(stat(filepath, &attributes) == -1){
    perror("Client : erreur stat");
    free(filepath);
    close(ds);
    exit(1);
  }

  int file_size = attributes.st_size;  // c'est bon, j'ai obtenu la taille du fichier. Refléchir ce que je dois en fair .

  snd = sendData(ds, (char*)&file_size, sizeof(int));
  /* Traiter TOUTES les valeurs de retour (voir le cours ou la documentation). */
   if (snd < 0) {
    //printf("Client : Erreur lors du send \n");
    perror("Client : Erreur lors du send \n");
    free(filepath);
    close(ds);
    exit(1);
   }
   if (snd == 0) {
    perror("Client : Serveur déconnecté \n");
    free(filepath);
    close(ds);
    exit(1);
   }

   printf("Client: je viens d'envoyer la taille du fichier : %d\n", file_size);

  // pour envoyer le contenu, je dois lire le fichier :
    FILE* file = fopen(filepath, "rb"); // ouverture en lecture
  if(file == NULL){
    perror("Client : erreur ouverture fichier \n");
    free(filepath);
    close(ds);
    exit(1);   
  }
  free(filepath); // je n'ai plus besoin de ce tableau dans la suite.

  // je fait une lecture par bloc.
  // je continue à lire tant que je n'ai pas lus le fichier en entier.
  int nbRead = 0; //

  int nbSendCall = 0;

  while(nbRead < file_size){
    
    char buffer[MAX_BUFFER_SIZE];
    size_t read = fread(buffer, sizeof(char), MAX_BUFFER_SIZE, file);
    // je viens de tenter de lire un bloc d'au maximum MAX_BUFFER_SIZE octets
    if(read == 0){
      if(ferror(file) != 0){
      	perror("Client : erreur lors de la lecture du fichier \n");
      	fclose(file);
        close(ds);
      	exit(1);
      } // fin du fichier
      break; // plus rien à lire
    }
    // ici j'ai un bloc de read octets lus et stoqués dans buffer. Que faire de ce bloc d'octets ?
  
    snd = sendDataBis(ds, buffer, read, &nbSendCall);

    if (snd < 0) {
      //printf("Client : Erreur lors du send \n");
      perror("Client : Erreur lors du send \n");
      close(ds);
      fclose(file);
      exit(1);
     }
    if (snd == 0) {
      perror("Client : Serveur déconnecté \n");
      close(ds);
      fclose(file);
      exit(1);
    }
    
    nbRead += snd;
  }

  printf("j'ai fini d'envoyer le fichier\n");

  // fermeture du fichier
  int resc = fclose(file);
  if (resc != 0) {
    perror("fclose error \n");
  } else printf ("fermeture du fichier \n");
 
  printf("Client : j'ai envoye au total : %d octets,  envoyes en %ls appels a send \n", totalSent, &nbSendCall);  
  close (ds);
  printf("Client : je termine\n");
}
