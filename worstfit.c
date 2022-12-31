#include<stdio.h>

int main(){
	int m,p;
	printf("\nEnter the no. of main memory and process");
	scanf("%d %d",&m,&p);
	int memory[m],process[p],allocate[p],occupied[m];
	for(int i=0;i<m;i++){
		printf("\nBlock %d:",i);
		scanf("%d",&memory[i]);
	}
	for(int i=0;i<p;i++){
		printf("\nProcess %d:",i);
		scanf("%d",&process[i]);
	}
	for(int i=0;i<m;i++)
		occupied[i]=0;
	for(int i=0;i<p;i++)
		allocate[i]=-1;
		
	for(int i=0;i<p;i++){
		int index=-1;
		for(int j=0;j<m;j++){
			if((memory[j]>=process[i]) && !occupied[j]){
				if(index==-1){
					index=j;}
				else if(memory[index]<memory[j]){
					index=j;}
			}
		}
		if(index!=-1){
			occupied[index]=1;
			allocate[i]=index;
			memory[index]-=process[i];
		}
	}
	printf("\nProcess\tBlocksize\tBlock no");
	for(int i=0;i<p;i++){
		printf("\n%d\t%d",i,process[i]);
		if(allocate[i]!=-1)
			printf("\t%d",allocate[i]+1);
		else
			printf("\tNA");
	}
	return 0;
}
