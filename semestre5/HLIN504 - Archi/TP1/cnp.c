#include <stdio.h>
#include <stdlib.h>
#include "fact.c"

int** pascal(int n)
{
	if (n == 1) {
		return 1;
	}
	else {
		int **triangle = (int **)malloc(n * sizeof(int*));
		for(int i = 0; i < n; i++) {
			*(triangle + i) = (int *)malloc(n*sizeof(int*));
			*triangle + i = 
		}
	}
}

int main(int argc, char const *argv[])
{
	if (argc == 1) {
		printf("Il faut un parametre ! \n");
		exit(1);
	}
	else if (argc > 2) {
		printf("Il y a un parametre en trop ! \n");
		exit(1);
	}
	else if (argc > 1) {
		long long unsigned answer = fact(atoi(argv[1]));
		printf("La réponse est : %llu \n", answer);
	}
	return EXIT_SUCCESS;
}