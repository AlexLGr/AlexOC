#include<stdio.h> 

void swap(int *x, int *y){ 
    int temp = *x; 
    *x = *y; 
    *y = temp; 
} 
int partitioning (int array[], int lower, int higher){ 
    int pivot = array[higher];
    int i = (lower - 1);
  
    for (int j = lower; j < higher; j++){ 
        if (array[j] < pivot){ 
            i++;
            swap(&array[i], &array[j]); 
        } 
    } 
    swap(&array[i + 1], &array[higher]); 
    return (i + 1); 
} 

void quickSort(int array[], int lower, int higher){ 
    if (lower < higher){ 
        int pivot = partitioning(array, lower, higher); 
        quickSort(array, lower, pivot - 1); 
        quickSort(array, pivot + 1, higher); 
    } 
} 
  
void printArray(int array[], int size){ 
    for (int i=0; i < size; i++) 
        printf("%d ", array[i]); 
    printf("\n"); 
} 
  
int main(){ 
    int arr[] = {62,17,8,25,10,1,23,44}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    quickSort(arr, 0, n-1); 
    printf("Sorted array: "); 
    printArray(arr, n); 
    return 0; 
}