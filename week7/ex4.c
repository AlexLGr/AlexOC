#include <stdio.h>
#include <stdlib.h>

void* reallocAlex(void *ptr, size_t size) {
	if (ptr == NULL) {
		return malloc(size);
	} 
	
	if(size==0){
		free(ptr);
		return NULL;
	}else{
		void *ptr2 = malloc(size);
		for(int i = 0; i<size; i++){
			*((char*)ptr2 + i) = *((char*)ptr + i);
		}
		free(ptr);
		return ptr2;
	}
}

int main() {
	printf("Enter original array size:");
	int n1=0;
	scanf("%d",&n1);

	int* a1 = (int*)malloc(n1*sizeof(int));
	int i;
	for(i=0; i<n1; i++){
		*(a1+i)=100;
		
		printf("%d ",*(a1+i) );
	}
	
	printf("\nEnter new array size: ");
	int n2=0;
	scanf("%d",&n2);
	
	a1 = (int*)reallocAlex(a1,n2*sizeof(int));
	for(i=0; i<n2;i++){
		printf("%d ",*(a1+i));
	}
	printf("\n");
	
	return 0;
}

