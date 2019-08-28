#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv){
	int n = atoi(argv[1]);
	
	int j = 0;
	
	for(int i=1; i<=n; ++i){
		for(int space = 1; space<=(n-i); ++space){
			printf("  ");
		}
		
		while(j!=(2*i-1)){
			printf("* ");
			j++;
		}
		
		j = 0;
		
		printf("\n");
	}
	
	return 0;
}