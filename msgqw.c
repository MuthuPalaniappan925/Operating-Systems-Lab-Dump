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
	msg.b=1;
	printf("\nString:");
	fgets(msg.t,100,stdin);
	msgsnd(msgid,&msg,sizeof(msg),0);
	return 0;
}
