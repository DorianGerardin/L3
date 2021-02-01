#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[], char *env[])
{
	if (argc == 0) {
		printf("Il n'y a pas d'arguments");
		exit(1);
	}
	else {
		printf("Nombre de paramètres : %i \n", argc);
		for (int i = 0; i < argc; ++i) {
			printf("Paramètre %i : %s \n", i, *(argv + i));
		}
		int nbEnv = 0;
		for (int i = 0; *(env + i) != NULL; ++i)
		{
			nbEnv++;
			printf("Variable d'environnement %i : %s \n", i, *(env + i));
		}
		printf("Nombre de variables d'environnement : %i \n", nbEnv);
	}
	return EXIT_SUCCESS;
}