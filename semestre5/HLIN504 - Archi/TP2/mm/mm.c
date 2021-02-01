#include "mm.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

mm mm_creer(){

	srand(time(NULL));
	
	mm jeu = (mm)malloc(sizeof(mm));
	for (int i = 0; i < TAILLE; ++i) {
		jeu -> secret[i] = (char)(rand() % 10);	
		printf("%i\n", jeu -> secret[i]);
	}
	jeu -> nbessais = 0;
	return jeu;
}

void mm_detruire(mm jeu){
	free(jeu);
}

int mm_test(mm jeu, char* essai) {
	int nbBienPlaces = 0;
	int nbMalPlaces = 0;
	int res = 0;

	int essaiTaille = 0;
	int i = 0;
	while (essai[i] != '\0') {
		if(essai[i] >= '0' && essai[i] <= '127') {
			return -1;
		}
		i++;
	}
	essaiTaille = i;

	if(essaiTaille > TAILLE+1) {
		return -1;
	}

	for (int i = 0; i < TAILLE; ++i)
	{
		if(*(essai+i) == *(jeu -> secret+i)) {
			nbBienPlaces++;
		}
	}

	jeu -> nbessais++;

	res = (TAILLE+1) * nbBienPlaces + nbMalPlaces;

	return res;
}

int mm_nbessais(mm jeu) {
	return jeu -> nbessais;
}