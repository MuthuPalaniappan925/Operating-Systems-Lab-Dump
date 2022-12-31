#include<stdio.h>

struct process{
	int pid,at,bt;
	};
	
int main(){
	int n;
	printf("\nEnter no. of process:");
	scanf("%d",&n);
	struct process p[n];
	for(int i=0;i<n;i++){
		p[i].pid=i;
		printf("\nEnter arrivaltime,burst time");
		scanf("%d %d",&p[i].at,&p[i].bt);
	}
	struct process a;
	int st=0,et=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<(n-i-1);j++){
			if(p[j].bt>p[j+1].bt){
				a=p[j];
				p[j]=p[j+1];
				p[j+1]=a;
			}
		}
	}
	for(int i=0;i<n;i++){
		if(p[i].bt==p[i+1].bt){
			if(p[i].at>p[i+1].at){
				a=p[i];
				p[i]=p[i+1];
				p[i+1]=a;
			}
		}
		if(et<p[i].at){
			et=p[i].at;
			st=et;
		}
	printf("\nP%d-->%d",p[i].pid,st);
	st+=p[i].bt;
	printf("-%d",st);
	et=st;
	}
	return 0;
}
	
	
	

