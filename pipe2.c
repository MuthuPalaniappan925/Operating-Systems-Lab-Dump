#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>

int main(){
	int fd1[2],fd2[2];
	int p;
	pipe(fd1);
	pipe(fd2);
	p=fork();
	if (p==0){
		close(fd1[0]);
		close(fd2[1]);
		int x;
		read(fd2[0],&x,sizeof(x));
		printf("\nReceived %d from parent",x);
		x+=94;
		write(fd1[1],&x,sizeof(x));
		close(fd1[1]);
		close(fd2[0]);
	}
	else{
		close(fd1[1]);
		close(fd2[0]);
		int y;
		y=56;
		write(fd2[1],&y,sizeof(y));
		read(fd1[0],&y,sizeof(y));
		printf("\nReceived from child: %d",y);
		close(fd1[0]);
		close(fd2[1]);
	}
	return 0;
}
