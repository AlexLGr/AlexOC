#include <stdio.h>
 
void swap(int*, int*);
 
int main()
{
   int a, b;
 
   printf("Enter a ");
   scanf("%d", &a);
   printf("Enter b ");
   scanf("%d",&b);
 
   swap(&a,&b);
 
   printf("\nAfter swap a = %d\n", a);
   printf("After swap b = %d\n", b);
 
   return 0;
}

void swap(int *a, int *b)
{
   int temp;
   temp  = *b;
   *b = *a;
   *a = temp;
}