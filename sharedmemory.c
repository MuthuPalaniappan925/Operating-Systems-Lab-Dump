#include<stdio.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<sys/ipc.h>
#include<unistd.h>

int main(){
	key_t key=ftok("file",54);
	int shmid=shmget(key,1024,0666|IPC_CREAT);
	char* str=(char*)shmat(shmid,0,0);
	printf("\nString:");
	gets(str);

	return 0;
}
