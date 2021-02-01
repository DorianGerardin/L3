#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){

	for(int i=0 ; i<4 ; i++){
		pid_t nPid;
		if ((nPid = fork())==0){
		printf("un nouveau descendant %d de parent %d ! i=%d\n",getpid(), getppid(),i);
	}else{
		int status;
		wait(&status);
		}//chaque parent attend la fin de ses enfants
	}
}