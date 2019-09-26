#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sigint_handler(int signal){
	printf("Signal %d was caught\n", signal);
}

int main(){
	signal(SIGINT, sigint_handler);
	int i=0;
	while(1);
	return 0;
}