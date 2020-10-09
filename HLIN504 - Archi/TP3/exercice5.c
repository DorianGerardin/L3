#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int contains(char c, char *tab, int nb_char) {

	for (int i = 0; i < nb_char; ++i)
	{
		if(*(tab+i) == c) {
			return 1;
		}
	}
	return 0;
}

int main(int argc, char const *argv[])
{
	if (argc == 1) {
		printf("Il faut un chemin de fichier ! \n");
		exit(1);
	}
	else if (argc > 2) {
		printf("Il y a un parametre en trop ! \n");
		exit(1);
	}
	else {

		int fd = open(argv[1], O_RDONLY);

		int length = lseek(fd, 0, SEEK_END);
		lseek(fd, 0, SEEK_SET);

		char presence[length];
		int nb_char = 0;

		char c;

		if(fd < 0) {
			printf("Erreur lors de l'ouverture du fichier ! \n");
			exit(1);
		} else {
			while(read(fd, &c, 1) > 0) {
				if(!contains(c, presence, nb_char)) {
					presence[nb_char] = c;
					nb_char++;
				}
			}
			printf("%i caractères différents : ", nb_char);
			for (int i = 0; i < nb_char; ++i)
			{
				printf("%c, ", presence[i]);
			}
			printf("\n");
		}
		close(fd);
	}

	return EXIT_SUCCESS;
}