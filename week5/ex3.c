#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int producer_sleep = 1;
int consumer_sleep = 0;
int count = 0;

int goods[] = {0,0,0,0,0,0,0,0,0,0};

int produce_goods(){
	int i = 0;
	if (goods[0]==1){
		consumer_sleep = 0;
	}
	while(i<10){
		if (goods[i]==0){
			break;
		}
		i++;
	}
	if(count==10){
		producer_sleep = 1;
	}else{
		goods[i]=1;
		count++;
	}
}

int consume_goods(){
	int i = 0;
	if (goods[9]==0){
		producer_sleep = 0;
	}
	while(i<10){
		if (goods[i]==0) {
			goods[i-1] = 0;
			count--;
			break;
		}
	}
	if (count==0){
		consumer_sleep = 1;
	}
}

void *consume(void *threadID) {
	while(1){
		if (consumer_sleep==0){
			consume_goods();
		} 
	}
}

void *produce(void *threadID) {
	int j = 0;
	int i = 0;
	while(1){
		if (producer_sleep==0){
			j++;
			if(j==10){
				printf("\nProducer is alive %d\n",i);
				j=0;
				i++;
			}
			produce_goods();
		}
	}
}

int main () {
	pthread_t producer;
	pthread_t consumer;
	int p = 1;
	int c = 2;
    pthread_create(&producer, NULL, produce, (void *)p);
	pthread_create(&consumer, NULL, consume, (void *)c);
	pthread_join(producer, NULL);
	pthread_join(consumer, NULL);
}
