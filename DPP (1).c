/*Importing the required lib*/
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
/* In our case we will be having 5 Philosopher(processes) and 5 spoon(resources)
 */
#define ph_no 5
#define spoon_no 5
/* creating 5 pthread array for the process and 5 mutex array for resources */
pthread_t philosopher[ph_no];
pthread_mutex_t spoon[spoon_no];
/* Creating a dinning function which will be doing
1-> Thinking
2-> Taking spoons
3-> Eating
4-> Drop spoons
5-> End
n- parameter = Philosopher Number
*/
void dinning(int n) {
  printf("Philosopher %d --- Thinking", n);
  /* Assumption that it will take left side spoon first */
  pthread_mutex_lock(&spoon[n]);
  pthread_mutex_lock(&spoon[(n + 1) % spoon_no]);
  /* Eating state */
  printf("Philosopher %d --- Eating", n);
  printf("Nice Food");
  sleep(5);
  /* unlocking resources to use another processes */
  pthread_mutex_unlock(&spoon[n]);
  pthread_mutex_unlock(&spoon[(n + 1) % spoon_no]);
  printf("Philosopher %d -> Finished", n);
}
int main(void) {
  void *msg;
  int stat; // to check the status of the creation
  /* Init semaphore array */
  for (int i = 0; i < spoon_no; i++) {
    stat = pthread_mutex_init(&spoon[i], NULL);
    if (stat == -1) {
      printf("Mutex init is Failed...");
      exit(1);
    }
  }
  /* Run the philosopher Threads into the  dinning() function */
  for (int i = 0; i < ph_no; i++) {
    stat = pthread_create(&philosopher[i], NULL, (void *)dinning, (int *)i);
    if (stat != 0) {
      printf("Thread Creation Error...");
    }
  }
  /* Joining the thread to execute below closing the execution of main thread */
  for (int i = 0; i < ph_no; i++) {
    stat = pthread_join(philosopher[i], &msg);
    if (stat != 0) {
      printf("Thread join Failed...");
    }
  }
}