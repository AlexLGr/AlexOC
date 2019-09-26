#include <string.h>
#include <stdio.h>
#include <unistd.h>

int main(){
	int pipefd[2];
	char string1[] = "I love Game of Thrones!";
	char string2[] = " ";
	
	printf("%s\n%s\n", string1, string2);
	pipe(pipefd);
	
	write(pipefd[1], string1, strlen(string1));
	close(pipefd[1]);
	read(pipefd[0], &string2, 200);
	
	printf("S1: %s\n S2: %s\n", string1, string2);
	close(pipefd[0]);
	return 0;
}