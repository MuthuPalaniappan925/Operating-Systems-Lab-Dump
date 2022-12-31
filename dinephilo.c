#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
#include<stdlib.h>

#define n 5
#define THINKING 2
#define HUNGRY 1
#define EATING 0
#define LEFT (phnum+4)%n
#define RIGHT (phnum+1)%n

int state[n];
int phil[n]={0,1,2,3,4};
sem_t mutex,s[n];


void eat(int phnum){
	if(state[phnum]==HUNGRY && state[LEFT]!=EATING && state[RIGHT]!=EATING){
		state[phnum]=EATING;
		sleep(2);
		printf("\nPhilosopher %d takes chopsticks %d and %d",phnum+1,LEFT+1,phnum+1);
		printf("\nPhilosopher %d is eating",phnum+1);
		sem_post(&s[phnum]);
	}
}
		


void take_chop(int phnum){
	sem_wait(&mutex);
	state[phnum]=HUNGRY;
	printf("\nPhilosopher %d is hungry",phnum+1);
	eat(phnum);
	sem_post(&mutex);
	sem_wait(&s[phnum]);
	sleep(1);
}

void put_chop(int phnum){
	sem_wait(&mutex);
	state[phnum]=THINKING;
	printf("\nPhilosopher %d puts chopsticks %d and %d",phnum+1,LEFT+1,phnum+1);
	printf("\nPhilosopher %d is thinking",phnum+1);
	eat(LEFT);
	eat(RIGHT);
	sem_post(&mutex);
}
			


void* philosopher(void *num){
	while(1){
		int* i=num;
		sleep(1);
		take_chop(*i);
		sleep(0);
		put_chop(*i);
	}
}
		



int main(){
	int i;
	pthread_t id[n];
	sem_init(&mutex,0,1);
	for(int i=0;i<n;i++)
		sem_init(&s[i],0,0);
	for(int i=0;i<n;i++){
		pthread_create(&id[i],NULL,philosopher,&phil[i]);
		printf("\nPhilosopher %d is thinking",i+1);
	}
	for(int i=0;i<n;i++)
		pthread_join(id[i],NULL);
	return 0;
}
	
