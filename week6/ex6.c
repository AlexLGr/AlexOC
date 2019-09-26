#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>

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
	int pipefd[2];
	pipe(pipefd);
	int child_1 = fork();
	
	if(child_1==0){
		int message;
		read(pipefd[0], &message, sizeof(int));
		close(pipefd[0]);
		printf("Received pid: %d\n", message);
		for(int i=0; i<5; i++){
			sleep(2);
			kill(message, SIGKILL);
		}
	}else{
		int child_2 = fork();
		if(child_2==0){
			signal(SIGSTOP, signal_handler);
			while(1){
				printf("Child_2 is alive");
				sleep(1);
			}
		}else{
			printf("Parent sends pid (%d) to child1\n", child_2);
			write(pipefd[1], &child_2, sizeof(int));
			close(pipefd[1]);
			
			int child_2_state;
			waitpid(child_2, &child_2_state, 0);
			if(child_2_state==9){
				printf("Child_2 is killed\n");
			}
		}
	}
	return 0;
}