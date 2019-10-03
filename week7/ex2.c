#include <stdio.h>
#include <stdlib.h>

int main(){
	int N = 0;
	
	printf("N = ");
	scanf("%d",&N);
	
	int *array = (int*)malloc(N*sizeof(int));
	for(int i = 0; i<N; i++){
		*(array+i) = i;
		printf("%d\n",*(array+i));
	}
	free(array);
}