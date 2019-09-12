#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

void main(void){

	for(int i=0; i<5; i++){
		fork();
		sleep(5);
	}
}