#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	printf("Bonsoooooiir\n");
	execl("/bin/ls", NULL);
	return EXIT_SUCCESS;
}