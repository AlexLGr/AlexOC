#include <unistd.h>
#include <signal.h>
#include <stdio.h>

int main(){
	int child = fork();
	if (child == 0){
		while(1){
			printf("I am alive\n");
			sleep(1);
		}
	}else{
		sleep(10);
		kill(child, SIGTERM);
	}
	return 0;
}