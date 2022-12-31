#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
	int f;
	char s[100];
	while(1){
		f=open("chat",O_RDONLY);
		read(f,&s,sizeof(s));
		printf("%s\n",s);
	}
	return 0;
}

