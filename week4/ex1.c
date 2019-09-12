#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

void main(void){

	pid_t pid;
	int n = 3;
	pid = fork();
	if(pid==0){
		printf("Hello from child [%d - %d]\n", getpid(),n);
	}else{
		printf("Hello from parent [%d - %d]\n", getpid(),n);
	}
}
