#include <unistd.h>
#include <signal.h>
#include <stdio.h>

void signal_handler(int signal){
	if(signal == SIGSTOP){
		printf("Pause signal\n");
	}
	if(signal == SIGUSR1){
		printf("User defined signal 1\n");
	}
	if(signal == SIGKILL){
		printf("Kill\n");
	}
}

int main(){
	signal(SIGSTOP, signal_handler);
	signal(SIGUSR1, signal_handler);
	signal(SIGKILL, signal_handler);
	
	while(1);
	return 0;
}