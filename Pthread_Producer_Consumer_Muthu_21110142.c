//Muthu_21110142

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<semaphore.h>

//In this program we will try to have 5 consumer and 5 Producer
//producer - will provide data
//consumer - will read and recieve the data

#define max 5
#define buffer_size 5  

//declaring buffer array and mutex variable

int buffer[buffer_size];
pthread_mutex_t x;

//init semaphore variables

sem_t Buffer_Full;
sem_t Buffer_Empty;

//declaring variables to keep track of index

int in = 0;
int out = 0;

//Producer -Method
//p_no - Producer Number
//sem_wait ---> Wait()
//sem_post ---> Signal()

void *producer(void *p_no){
    int data;
    for(int i =0;i<max;i++){
        data = rand()%100;
        sem_wait(&Buffer_Empty);
        pthread_mutex_lock(&x);

        buffer[in] = data;
        printf("Producer_Number: %d -- Insert Item : %d -- Index :  %d\n", *((int *)p_no),buffer[in],in);
        in = (in+1)%buffer_size;
        
        pthread_mutex_unlock(&x);
        sem_post(&Buffer_Full);
    }
}

//consumer - method
//c_no - Consumer Number

void *consumer(void *c_no){
    for(int i =0;i<max;i++){
        sem_wait(&Buffer_Full);
        pthread_mutex_lock(&x);

        int data = buffer[out];
        printf("Consumer_Number : %d -- Remove Item : %d -- Index :  %d\n",*((int *)c_no),data, out);
        out = (out+1)%buffer_size;

        pthread_mutex_unlock(&x);
        sem_post(&Buffer_Empty);
    }
}

int main(){
    
    //creating producer and consumer array
    pthread_t p_no[5] , c_no[5];
    //init mutex and semaphore
    pthread_mutex_init(&x,NULL);
    sem_init(&Buffer_Empty,0,buffer_size);
    sem_init(&Buffer_Full,0,0);
    int a[5] = {1,2,3,4,5}; //Just used for numbering the producer and consumer

    for(int i = 0; i < 5; i++) {
        pthread_create(&p_no[i], NULL, (void *)producer, (void *)&a[i]);
    }
    for(int i = 0; i < 5; i++) {
        pthread_create(&c_no[i], NULL, (void *)consumer, (void *)&a[i]);
    }

    for(int i = 0; i < 5; i++) {
        pthread_join(p_no[i], NULL);
    }
    for(int i = 0; i < 5; i++) {
        pthread_join(c_no[i], NULL);
    }

    pthread_mutex_destroy(&x);
    sem_destroy(&Buffer_Empty);
    sem_destroy(&Buffer_Full);

    return 0;
   
}