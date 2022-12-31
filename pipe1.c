#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>

int main(){
	int fd[2],n;
	pid_t f;
	pipe(fd);
	f=fork();
	char b[100];
	if(f>0){
		printf("\nParent to Child");
		write(fd[1],"\nHello World",12);
		wait(NULL);
	}
	else{
		printf("\nReceived from parent");
		n=read(fd[0],b,100);
		write(1,b,n);
	}
	return 0;
}	
		
