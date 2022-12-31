#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
	int n;
	printf("\nSize:");
	scanf("%d",&n);
	int arr[n];
	int r=n/2;
	int fd[2];
	printf("\nEnter the elements");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	int fd1[2],fd2[2];
	pipe(fd1);
	pipe(fd2);
	int p;
	p=fork();
	if(p==0){
		close(fd1[0]);
		close(fd2[1]);
		int s;
		read(fd2[0],&s,sizeof(s));
		for(int i=r;i<n;i++){
			s+=arr[i];
		}
		int s1=s;
		write(fd1[1],&s1,sizeof(s1));
		close(fd1[1]);
		close(fd2[0]);
	}
	else{
		close(fd1[1]);
		close(fd2[0]);
		int s1;
		for(int i=0;i<r;i++){
			s1+=arr[i];
		}
		write(fd2[1],&s1,sizeof(s1));
		read(fd1[0],&s1,sizeof(s1));
		printf("\nTotal sum is: %d",s1);
		close(fd1[0]);
		close(fd2[1]);
	}
	return 0;
}
	
		
	
