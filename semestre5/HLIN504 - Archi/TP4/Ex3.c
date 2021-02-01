#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

int int main(int argc, char const *argv[])
{
	fork();
	printf("un nouveau descendant %d de parent %d !\n",getpid(), getppid());
	return EXIT_SUCCESS;	
}