#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 10

void *print_text(void *threadID) {
   long tID;
   tID = (long)threadID;
   printf("Some text; thread ID - %d\n", tID);
   pthread_exit(NULL);
}

int main () {
   pthread_t threads[NUM_THREADS];
   int error;
   int i;
   for( i = 0; i < NUM_THREADS; i++ ) {
      printf("Main() is creating a thread - %d\n", i);
      error = pthread_create(&threads[i], NULL, print_text, (void *)i);
      if (error) {
         printf("Error in thread creation - %d\n", error);
         exit(-1);
      }
	  pthread_join(threads[i], NULL);
   }
   pthread_exit(NULL);
}