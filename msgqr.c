#include<stdio.h>
#include<sys/msg.h>
#include<sys/ipc.h>

struct node{
	long int b;
	char t[100];
	};


int main(){
	struct node msg;
	key_t key=ftok("file",45);
	int msgid=msgget(key,0666|IPC_CREAT);
	msgrcv(msgid,&msg,sizeof(msg),1,0);
	printf("\n%s",msg.t);
	return 0;
	}
	
