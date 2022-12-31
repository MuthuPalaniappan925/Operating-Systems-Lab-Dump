#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
int buffer[3];
int add=0;
int rem=0;
int count=0;

pthread_mutex_t m=PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t c_prod=PTHREAD_COND_INITIALIZER;
pthread_cond_t c_cons=PTHREAD_COND_INITIALIZER;


void *producer(){
	int i;
	while(1){
		pthread_mutex_lock(&m);
		if(count>3)
			exit(1);
		while(count==3)
			pthread_cond_wait(&c_prod,&m);
		printf("\nNumber:");
		scanf("%d",&i);
		buffer[add]=i;
		count++;
		add=(add+1)%3;
		pthread_mutex_unlock(&m);
		pthread_cond_signal(&c_cons);
		printf("\nPrducer inserted:%d",i);
		fflush(stdout);
	}
	printf("\nProducer quitting");
	fflush(stdout);
	}
	
void *consumer(void *param){
	int i;
	while(1){
		pthread_mutex_lock(&m);
		if(count<0)
			exit(1);
		while(count==0)
			pthread_cond_wait(&c_cons,&m);
		i=buffer[rem];
		count--;
		rem=(rem+1)%3;
		pthread_mutex_unlock(&m);
		pthread_cond_signal(&c_prod);
		printf("\nConsumer value:%d",i);
		fflush(stdout);
	}
	printf("\nConsumer quitting");
	fflush(stdout);
}
	


void main(int argc,char *argv[]){
	pthread_t t1,t2;
	if(pthread_create(&t1,NULL,producer,NULL)){
		printf("\nUnable to create producer thread");
		exit(1);
	}
	if(pthread_create(&t2,NULL,consumer,NULL)){
		printf("\nUnable to create consumer thread");
	}
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
}
	
	
