#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>

int main(){
	int f;
	char s[100];
	while(1){
		f=open("chat",O_WRONLY);
		scanf("%[^\n]%*c",s);
		write(f,&s,sizeof(s));
	}
	return 0;
}
/
