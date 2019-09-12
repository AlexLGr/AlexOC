#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>

// The code for exercises 3 and 4 is the same since it handles both cases with arguments and without

void main(void){

	while(1){
		char string[100];
		fgets(string, 99, stdin);
		if (strncmp(string, "exit\n", 5)==0){
			break;
		}	
		system(string);
	}
}
