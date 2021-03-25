#include <stdio.h> 
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdlib.h>
#include<arpa/inet.h>
#include<string.h>

int sendData(int sock, char* msg, int sizeMsg);

int sendDataBis(int sock, char* msg, int sizeMsg, int* nbCallSend);

int rcvData(int sock, char* msg, int sizeMsg);