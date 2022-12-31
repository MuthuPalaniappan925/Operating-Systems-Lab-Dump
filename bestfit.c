#include<stdio.h>

int main(){
	int m,p,i,j;
	printf("Enter the number of main memory and processes: ");
	scanf("%d %d",&m,&p);
	int memory[m],process[p],allocate[p],occupied[m];
	printf("\nSize of main memeory");
	for(int i=0;i<m;i++){
		printf("\nBlock %d:",i+1);
		scanf("%d",&memory[i]);
	}
	printf("\nSize of each process");
	for(int i=0;i<p;i++){
		printf("Process %d:",i+1);
		scanf("%d",&process[i]);
	}
	for(int i=0;i<m;i++){
		occupied[i]=0;
	}
	for(int i=0;i<p;i++){
		allocate[i]=-1;
	}
	for(int i=0;i<p;i++){
		int index=-1;
		for(int j=0;j<m;j++){
			if((memory[j]>=process[i]) && !occupied[j]){
				if(index==-1){
					index=j;}
				else if(memory[index]>memory[j]){
					index=j;}
			}
		}
		if(index!=-1){
			allocate[i]=index;
			occupied[index]=1;
			memory[index]-=process[i];
		}
	}
	printf("\nProcess\tProcess Size\tBlock No");
	for(int i=0;i<p;i++){
	printf("\n%d \t%d",i,process[i]);
	if(allocate[i]!=-1)
		printf(" \t%d",allocate[i]+1);
	else
		printf(" \tNot allocated");
	}
	return 0;
}

