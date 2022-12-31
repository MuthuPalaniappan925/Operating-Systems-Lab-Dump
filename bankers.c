#include<stdio.h>

int main(){
	int n,r;
	printf("\nEnter no. of process and resources: ");
	scanf("%d %d",&n,&r);
	int allocation[n][r],max[n][r],available[r];
	for(int i=0;i<n;i++){
		printf("\nProcess %d: ",i);
		for(int j=0;j<r;j++){
			scanf("%d",&allocation[i][j]);
		}
	}
	for(int i=0;i<n;i++){
		printf("\nMax resources for Process %d: ",i);
		for(int j=0;j<r;j++){
			scanf("%d",&max[i][j]);
		}
	}
	printf("\nResources available:");
	for(int i=0;i<r;i++){
		scanf("%d",&available[i]);
	}
	int f[n],answer[n];
	for(int i=0;i<n;i++)
		f[i]=0;
	int need[n][r],index=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			need[i][j]=max[i][j]-allocation[i][j];
		}
	}
	
	for(int k=0;k<=n;k++){
		for(int i=0;i<n;i++){
			if(f[i]==0){
				int flag=0;
				for(int j=0;j<r;j++){
					if(need[i][j]>available[j]){
						flag=1;
						break;
					}
				}
				if(flag==0){
					answer[index++]=i;
					for(int y=0;y<n;y++){
						available[y]+=allocation[i][y];
					}
					f[i]=1;
				}
			}
		}
	}
	printf("\nSafe Sequence is:\n");
	for(int i=0;i<n;i++)
		printf("P%d-->",answer[i]);
	return 0;
}
	
