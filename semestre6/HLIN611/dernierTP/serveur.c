#include <stdio.h> 
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdlib.h>
#include<arpa/inet.h>
#include<string.h>
#include "common.c"


#define MAX_BUFFER_SIZE 16000 // taille du buffer qui me permet de récupérer le contenu du fichier à recevoir bloc par bloc. Vous pouvez changer cette valeur.



int main(int argc, char *argv[])
{
  
 /* boucle pour le traitement itératif des clients */
  while(1){



  int ds = socket(PF_INET, SOCK_STREAM, 0);

  if (ds == -1){
    perror("Serveur : probleme creation socket");
    exit(1); // je choisis ici d'arrêter le programme car le reste
       // dépendent de la réussite de la création de la socket.
  }

  printf("Serveur: creation de la socket : ok\n");

  struct sockaddr_in server;
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = inet_addr("192.168.1.55");
  server.sin_port = htons(60000);
  
  if(bind(ds, (struct sockaddr *) &server, sizeof(server)) < 0){
    perror("Serveur : erreur bind");
    close(ds); // je libère les ressources avant de terminer.
    exit(1); // je choisis de quitter le programme : la suite dépend de la réussite du nommage.
  }

  int ecoute = listen(ds, 5);
  if (ecoute < 0){
    printf("Serveur : je suis sourd(e)\n");
    close (ds);
    exit (1);
  } 

  printf("Serveur : mise en ecoute ok\n");
  printf("Serveur : j'attend la demande d'un client ...\n");


  while(1) {
    struct sockaddr_in adCv;
    socklen_t lgCv = sizeof(struct sockaddr_in);
    int dsCv = accept(ds, (struct sockaddr*)&adCv, &lgCv);
    if (dsCv < 0) {
      perror("Serveur : pb lors du accept");
      printf("ici 1\n");
      exit(1);
    } else {
      printf("Serveur : Le client %s:%d est connecté : \n", inet_ntoa(adCv.sin_addr), ntohs(adCv.sin_port));
    }

    int name_size;

    int rcv = rcvData(dsCv, (char*)&name_size, sizeof(int));

    if (rcv < 0) {
      //printf("Client : Erreur lors du send \n");
      perror("Serveur : Pb reception \n");
      printf("ici 2\n");
      close(dsCv);
      continue;
    }

    if (rcv == 0) {
      //printf("Client : Erreur lors du send \n");
      perror("Serveur : Client deconnecté \n");
      printf("ici 3\n");
      close(dsCv);
      continue;
    }
  
    // je doit recevoir des données me permettant d'obtenur le nom d'un fichier
    
    char* file_name = malloc(name_size);

    rcv = rcvData(dsCv, file_name, name_size);

    if (rcv < 0) {
      //printf("Client : Erreur lors du send \n");
      perror("Serveur : Pb reception nom fichier \n");
      printf("ici 4\n");
      free(file_name);
      close(dsCv);
      continue;
    }

    if (rcv == 0) {
      //printf("Client : Erreur lors du send \n");
      perror("Serveur : Client deconnecté \n");
      printf("ici 5\n");
      free(file_name);
      close(dsCv);
      continue;
    }

    printf("Serveur, je vais recevoir le fichier %s\n", file_name);

    // je construis le chemin vers le fichier à créer.
    char* filepath = malloc(name_size + 16); // ./reception/+nom fichier
    filepath[0] = '\0';
    strcat(filepath, "./reception/");
    strcat(filepath, file_name);
    free(file_name);

  // j'ouvre le fichier dans lequel je vais écrire
    FILE* file = fopen(filepath, "wb");
    if(file == NULL){  // servez vous de cet exemple pour le traitement des erreurs. 
      perror("Serveur : erreur ouverture fichier: \n");
      free(filepath);
      close (dsCv);
      continue; // passer au client suivant 
    }
    
    free(filepath); // je n'en ia plus besoin.

    //reception des données me permettant de recevoir correctement le contenu du fichier.
    int file_size;
  
    rcv = rcvData(dsCv, (char*)&file_size, sizeof(int));

    if (rcv < 0) {
      //printf("Client : Erreur lors du send \n");
      perror("Serveur : Pb reception de la taille du fichier\n");
      close(dsCv);
      continue;
    }

    if (rcv == 0) {
      //printf("Client : Erreur lors du send \n");
      perror("Serveur : Client deconnecté \n");
      close(dsCv);
      continue;
    }

    printf("Serveur, je dois recevoir %d octets (contenu)\n", file_size);
      
    int contentReceived = 0; // Compte le nombre d'octets du fichier reçu

    int nbCallRecv = 0;

    // je reçois le contenu progressivement 
    while(contentReceived < file_size){
      
      char buffer[MAX_BUFFER_SIZE];
      rcv = recv(dsCv, buffer, MAX_BUFFER_SIZE, 0);  // /!\ ici appel
						     // direct de recv
						     // car recvTCP
						     // n'est pas
						     // adapté. Pourquoi ?

      if (rcv < 0) {
        //printf("Client : Erreur lors du send \n");
        perror("Serveur : Pb reception de la taille du fichier\n");
        fclose(file);
        break;
      }

      if (rcv == 0) {
        //printf("Client : Erreur lors du send \n");
        perror("Serveur : Client deconnecté \n");
        fclose(file);
        continue;
      }

      nbCallRecv++;
	
      // si pas d'erreurs, j'ai reçu rcv octets. Je dois les écire dans le fichier.
      size_t written = fwrite(buffer, sizeof(char), rcv, file);
      if(written < rcv){
      	perror("Serveur : Erreur a l'ecriture du fichier \n");
      	fclose(file);
      	break; // je sors de la boucle d'écrture/réception.
      }
      contentReceived += rcv;
    }

    // fermeture du fichier à la fin de son écriture ou si erreur s'est produite.
    
    fclose(file);
    printf("Serveur : fin du dialogue avec le client, nombre total d'octets recus : %d,  recus en %d appels a recv \n", contentReceived, nbCallRecv);
    close (dsCv);
    //je passe au client suivant.
  }
  
  close (ds); // atteignable si on sort de la boucle infinie.
  printf("Serveur : je termine\n");
 }
}








