#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdlib.h>
#include<arpa/inet.h>
#include<string.h>


// ce programme est à compléter en fonction des instructions à
// recevoir depuis un processus serveur TCP distant. L'IP et le numéro de
// port du serveur sont fournis en début d'épreuve par les enseignants
// et sont à passer en paramètres de votre programme.

// Une instruction est sous forme de chaine de caractères (caractère
// de fin de chaine inclus) dont la taille (de type int) est à
// recevoir juste avant le texte de l'instruction. Donc, une
// instruction implique deux messages : un premier message qui est la
// taille (en nombre d'octets) du texte de l'instruction et un second
// message qui est le texte de l'instruction.

// Après execution d'une instruction, votre programme recoit un
// feedback avec l'instruction suivante. Là aussi, deux messages sont
// à recevoir : le premier qui est la taille (de type int) en nombre
// d'octets du second mesage qui est une chaine de caractères
// (caractère de fin inclus).

// Remarque 1 : un message de type chaine de caractères ne depassera jamais 6000 octets.


int main(int argc, char *argv[]) {

  if (argc != 4){
    printf("Utilisation : %s ip_serveur port_serveur param3 \n param3 est un entier dont la signification sera fournie par une instruction. En attendant cette instruction, passer n'importe quelle valeur\n", argv[0]);
    exit(1);
  }

  int ds = socket(PF_INET, SOCK_STREAM, 0);

  struct sockaddr_in server;
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = inet_addr(argv[1]);
  server.sin_port = htons((short) atoi(argv[2]));

  int conn = connect(ds, (struct sockaddr *) &server, sizeof(struct sockaddr_in));

  if (conn <0){
    perror ("Client: pb au connect :");
    close (ds); 
    exit (1); 
  }

  printf("Client : demande de connexion reussie \n");

  //-----------Reception Taille Instruction--------------//

  int instr_size;

  int rcv = recv (ds, &instr_size, sizeof(int), 0) ;
  /* Traiter TOUTES les valeurs de retour (voir le cours ou la documentation). */
  if(rcv < 0) {
    perror("Client : Problème de reception de la taille de l'instruction 1 \n");
    close(ds);
    exit(1);
  }
  if (rcv == 0) {
    printf("Client : serveur déconnecté \n");
    close(ds);
    exit(1);
  }

  printf("Réponse du serveur (taille instruction) : %d \n", instr_size);

  //-------------------Reception Instruction------------------//

  char instr[6000]; 

  rcv = recv (ds, (char *)&instr, instr_size, 0) ;
  if(rcv < 0) {
    perror("Client : Problème de reception de l'instruction 1 \n");
    close(ds);
    exit(1);
  }
  if (rcv == 0) {
    printf("Client : serveur dconnecté \n");
    close(ds);
    exit(1);
  }

  printf("Réponse du serveur (msg instruction) : %s \n", instr);


  //------------------Renvoie message------------------//

  int snd = send(ds, instr, instr_size, 0);
  if (snd < 0) {
	  perror("Client : Erreur lors du send \n");
	  close(ds);
	  exit(1);
  }
  if (snd == 0) {
	  perror("Client : Serveur déconnecté \n");
	  close(ds);
	  exit(1);
  }

  printf("Client : j'ai déposé %d octets \n", snd);


  //----------------Reception Taille Instruction n°2-----------------//

  int instr_size2;

  rcv = recv (ds, &instr_size2, sizeof(int), 0) ;
  /* Traiter TOUTES les valeurs de retour (voir le cours ou la documentation). */
  if(rcv < 0) {
    perror("Client : Problème de reception de la taille de l'instruction 2 \n");
    close(ds);
    exit(1);
  }
  if (rcv == 0) {
    printf("Client : serveur déconnecté \n");
    close(ds);
    exit(1);
  }

  printf("Réponse du serveur (taille instruction n°2) : %d \n", instr_size2);


  //-------------------Reception Instruction n°2------------------//

  char instr2[6000]; 

  rcv = recv (ds, (char *)&instr2, instr_size2, 0) ;
  if(rcv < 0) {
    perror("Client : Problème de reception de l'instruction 2 \n");
    close(ds);
    exit(1);
  }
  if (rcv == 0) {
    printf("Client : serveur dconnecté \n");
    close(ds);
    exit(1);
  }

  printf("Réponse du serveur (msg instruction n°2) : %s \n", instr2);


  //-----------------------Serveur TCP----------------------//

  int dsServ = socket(PF_INET, SOCK_STREAM, 0);

  if (dsServ == -1){
    perror("Serveur : probleme creation socket");
    exit(1);
  }
  
  printf("Serveur TCP : creation de la socket : ok\n");

  struct sockaddr_in ad;
  ad.sin_family = AF_INET;
  ad.sin_addr.s_addr = INADDR_ANY;
  ad.sin_port = htons((short) atoi(argv[3]));
  
  if(bind(dsServ, (struct sockaddr *) &ad, sizeof(ad)) < 0){
    perror("Serveur TCP : erreur bind");
    close(dsServ);
    exit(1);
  }

  printf("Serveur TCP : nommage : ok\n");

  int ecoute = listen(dsServ, 1);
  if (ecoute < 0){
    printf("Serveur : je suis sourd(e)\n");
    close (dsServ);
    exit (1);
  } 
 
  printf("Serveur: mise en écoute : ok\n");

  short port = (short) atoi(argv[3]);

  snd = send(ds, (short *)&port, sizeof(short), 0);
  if (snd < 0) {
	  perror("Client : Erreur lors du send du port\n");
	  close(ds);
	  exit(1);
  }
  if (snd == 0) {
	  perror("Client : Serveur déconnecté \n");
	  close(ds);
	  exit(1);
  }

  printf("Client : j'ai déposé %d octets (port)\n", snd);

  printf("Serveur TCP : j'attends la demande d'un client (accept) \n"); 
  
  struct sockaddr_in adCv ;
  socklen_t lgCv = sizeof (struct sockaddr_in);

  int dsCv = accept(dsServ, (struct sockaddr *)& adCv, &lgCv);
  if (dsCv < 0){
    perror ("Serveur TCP, probleme accept :");
    close(dsServ);
    exit (1);
  }

  printf("Serveur TCP : le client %s:%d est connecté  \n", inet_ntoa(adCv.sin_addr), ntohs(adCv.sin_port));


  //--------------------Reception Taille Instruction n°3-----------------//

  int instr_size3;

  rcv = recv (dsCv, &instr_size3, sizeof(int), 0) ;
  /* Traiter TOUTES les valeurs de retour (voir le cours ou la documentation). */
  if(rcv < 0) {
    perror("Client : Problème de reception de la taille de l'instruction 3 \n");
    close(ds);
    exit(1);
  }
  if (rcv == 0) {
    printf("Client : serveur déconnecté \n");
    close(ds);
    exit(1);
  }

  printf("Réponse du serveur (taille instruction n°3) : %d \n", instr_size3);

  //-----------------------Reception Instruction n°3----------------------//

  char instr3[6000]; 

  rcv = recv (dsCv, (char *)&instr3, instr_size3, 0) ;
  if(rcv < 0) {
    perror("Serveur TCP : Problème de reception de l'instruction 3 \n");
    close(ds);
    exit(1);
  }
  if (rcv == 0) {
    printf("Serveur TCP : client déconnecté \n");
    close(ds);
    exit(1);
  }

  printf("Réponse du Client (msg instruction n°3) : %s \n", instr3);

  //-----------------------Reception taille message----------------------//

  int mess_size;

  rcv = recv (dsCv, &mess_size, sizeof(int), 0) ;
  /* Traiter TOUTES les valeurs de retour (voir le cours ou la documentation). */
  if(rcv < 0) {
    perror("Serveur TCP : Problème de reception de la taille du message \n");
    close(dsCv);
    exit(1);
  }
  if (rcv == 0) {
    printf("Serveur TCP : client déconnecté \n");
    close(dsCv);
    exit(1);
  }

  printf("Réponse du client (taille message) : %d \n", mess_size);

  //-----------------------Reception message----------------------//

  char mess[6000]; 

  rcv = recv (dsCv, (char *)&mess, mess_size, 0) ;
  if(rcv < 0) {
    perror("Serveur TCP : Problème de reception de l'instruction 3 \n");
    close(dsCv);
    exit(1);
  }
  if (rcv == 0) {
    printf("Serveur TCP : client déconnecté \n");
    close(dsCv);
    exit(1);
  }

  printf("Réponse du Client (msg) : %s \n", mess);

  //----------------------Renvoie message---------------------//

  snd = send(dsCv, mess, mess_size, 0);
  if (snd < 0) {
	  perror("Serveur TCP : Erreur lors du send \n");
	  close(dsCv);
	  exit(1);
  }
  if (snd == 0) {
	  perror("Serveur TCP : Client déconnecté \n");
	  close(dsCv);
	  exit(1);
  }

  printf("Serveur TCP : j'ai déposé %d octets \n", snd);


  //----------------Reception Taille Instruction n°4-----------------//

  int instr_size4;

  rcv = recv (dsCv, &instr_size4, sizeof(int), 0) ;
  /* Traiter TOUTES les valeurs de retour (voir le cours ou la documentation). */
  if(rcv < 0) {
    perror("Serveur TCP : Problème de reception de la taille de l'instruction 4 \n");
    close(dsCv);
    exit(1);
  }
  if (rcv == 0) {
    printf("Serveur TCP : Client déconnecté \n");
    close(dsCv);
    exit(1);
  }

  printf("Réponse du Client (taille instruction n°4) : %d \n", instr_size4);


  //-------------------Reception Instruction n°4------------------//

  char instr4[6000]; 

  rcv = recv (dsCv, (char *)&instr4, instr_size4, 0) ;
  if(rcv < 0) {
    perror("Serveur TCP : Problème de reception de l'instruction 4 \n");
    close(dsCv);
    exit(1);
  }
  if (rcv == 0) {
    printf("Serveur TCP : serveur dconnecté \n");
    close(dsCv);
    exit(1);
  }

  printf("Réponse du serveur (msg instruction n°4) : %s \n", instr4);
 
  printf("Serveur : fin du dialogue avec le client\n");
  close (dsCv);
  
  close (ds);
  printf("Serveur : je termine\n");

  // première étape : se connecter au serveur et recevoir la première
  // instruction (lire commentaire plus haut). Bien évidement, il est
  // necessaire d'afficher le message reçu pour prendre connaissance
  // des instructions à suivre pour compléter votre programme.
}


