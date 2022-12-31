#include<stdio.h>

struct process{
	int pid,at,bt,pr;
	};
	
int main(){
	int n;
	printf("\nEnter no. of process:");
	scanf("%d",&n);
	struct process p[n];
	for(int i=0;i<n;i++){
		p[i].pid=i;
		printf("\nEnter arrivaltime,burst time,priority");
		scanf("%d %d %d",&p[i].at,&p[i].bt,&p[i].pr);
	}
	struct process a;
	int st=0,et=0,flag=0;
	for(int i=0;i<n;i++){
		int a=p[0].at;
		if(a==p[i].at)
			flag=1;
		else
			flag=0;
	}
	
	if(flag!=0){
		for(int i=0;i<n;i++){
			for(int j=0;j<(n-i-1);j++){
				if(p[j].at>p[j+1].at){
					a=p[j];
					p[j]=p[j+1];
					p[j]=a;
				}
			}
		}
	}
	if(flag!=0){
		et=p[0].at;		
		for(int i=0;i<n;i++){

			if(et<=p[i].at){
				et=p[i].at;
				st=et;
			}
			int min=p[i].pr;
			for(int j=i+1;j<n;j++){
				if(min>p[j].pr && p[j].at<=et){
					min=p[j].pr;
					a=p[j];
					p[j]=p[j+1];
					p[j]=a;
				}
			}
			printf("\nP%d-%d",p[i].pid,st);
			st+=p[i].bt;
			printf("-%d",st);
			et=st;
		}
	}
	else{
		for(int i=0;i<n;i++){
			for(int j=0;j<(n-i-1);j++){
				if(p[j].pr>p[j+1].pr){
					a=p[j];
					p[j]=p[j+1];
					p[j]=a;
				}
			}
		}
		for(int i=0;i<n;i++){
			if(et<p[i].at){
				et=p[i].at;
				st=et;
			}
			printf("\nP%d-%d",p[i].pid,st);
			st+=p[i].bt;
			printf("-%d",st);
			et=st;
		}
	}
	return 0;
}
				
				
		
	

