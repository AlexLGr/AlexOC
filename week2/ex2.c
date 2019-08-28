#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	
   char string[1000];
   char reverse[1000];
   
   string[0] = '\0';
 
   printf("Input a string: ");
   gets(string);
   
   int i = 0, length = 0;
   while (string[i] != '\0'){
	   length++;
	   i++;
   }
 
   int j = 0;
 
   for (j; j < length; j++) {
      reverse[j] = string[length-1-j];
   }
 
   reverse[j] = '\0';
 
   printf("%s\n", reverse);
 
   return 0;
}