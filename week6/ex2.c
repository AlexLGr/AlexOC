#include <string.h>
#include <stdio.h>
#include <unistd.h>

int main(){
	int pipefd[2];
	char string1[] = "I love Game of Thrones!";
	char string2[] = " ";
	
	printf("%s\n%s\n", string1, string2);
	pipe(pipefd);
	
	if(fork()!=0){
		close(pipefd[0]);
		write(pipefd[1], string1, strlen(string1));
		close(pipefd[1]);
		printf("In parent: %s\n %s\n", string1, string2);
	}else{
		close(pipefd[1]);
		read(pipefd[0], &string2, 200);
		printf("In child: %s\n %s\n", string1, string2);
	}
	return 0;
}