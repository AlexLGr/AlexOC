#include <stdio.h>

void swap(int *x, int *y){  
    int temp = *x;  
    *x = *y;  
    *y = temp;  
}  

void bubble_sort(int a[], int s) {  
    int i, j;  
    for (i = 0; i < s-1; i++) {   
		for (j = 0; j < s-i-1; j++) { 
			if (a[j] > a[j+1])  
				swap(&a[j], &a[j+1]); 
		}
	}
}

void print_array(int a[], int size){
	for (int i = 0; i <size; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
}


int main(){
	int array[] = {4,5,12,1,8,7,3};
	int size = sizeof(array)/sizeof(array[0]);
	printf("Initial array: ");
	print_array(array, size);
	bubble_sort(array, size);
	printf("Sorted array: ");
	print_array(array, size);
	
}
