#include <stdio.h> 
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdlib.h>
#include<arpa/inet.h>
#include<string.h>
#include "common.h"

int sendData(int sock, char* msg, int sizeMsg) {
  ssize_t snd;
  ssize_t total_sent = 0;
  //int total_sent = 0;
  while(sizeMsg > 0) {
    snd = send(sock, msg, sizeMsg, 0);
    if (snd < 0) {
      return -1;
    } 
    if (snd == 0) {
      return 0;
    }

  //printf("Client : j'ai déposé %d octets \n", (int) snd);

    total_sent += snd;
    sizeMsg -= snd;
  }
  return total_sent;
}

int sendDataBis(int sock, char* msg, int sizeMsg, int* nbCallSend) {
	 ssize_t snd;
   ssize_t total_sent = 0;
  //int total_sent = 0;
  while(sizeMsg > 0) {
    snd = send(sock, msg, sizeMsg, 0);
    if (snd < 0) {
      return -1;
    } 
    if (snd == 0) {
      return 0;
    }

  //printf("Client : j'ai déposé %d octets \n", (int) snd);

    total_sent += snd;
    sizeMsg -= snd;
    (*nbCallSend)++;
  }
  return total_sent;
}

int rcvData(int sock, char* msg, int sizeMsg) {
  ssize_t received;
  ssize_t total_rcv = 0;
  //int total_sent = 0;
  while(sizeMsg > 0) {
    received = send(sock, msg, sizeMsg, 0);
    if (received < 0) {
      return -1;
    } 
    if (received == 0) {
      return 0;
    }

  //printf("Client : j'ai déposé %d octets \n", (int) snd);

    total_rcv += received;
    sizeMsg -= received;
  }
  return total_rcv;
}