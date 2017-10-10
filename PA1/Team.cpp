#include <stdio.h>
#include <cmath>

const int Max=500005;

int A[Max];
int B[Max];
int C[Max];

int tag[Max]={0};

char ABC[Max];


int main(){
	int n,k;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&A[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&B[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&C[i]);
	}
	
	scanf("%d",&k);
	
	int countA=1,countB=1,countC=1;	
	for(int i=1;i<=n;i++){
		int t=i%3;
		if(t==1){
		     //A
			int tmp=A[countA];
			while(tag[tmp]==1){
				countA++;
				tmp=A[countA];
			}

			if(tag[tmp]==0){
				tag[tmp]=1;
				ABC[tmp]='A';
				countA++;
			}
		}
		else if(t==2){
		     //B
			int tmp=B[countB];
			while(tag[tmp]==1){
				countB++;
				tmp=B[countB];
			}
			if(tag[tmp]==0){
				tag[tmp]=1;
				ABC[tmp]='B';
				countB++;
			}	
		}
		else if(t==0){     //C
			int tmp=C[countC];
			while(tag[tmp]==1){
				countC++;
				tmp=C[countC];
			}
			if(tag[tmp]==0){
				tag[tmp]=1;
				ABC[tmp]='C';
				countC++;
			}	
		}
	}
	printf("%c\n",ABC[k]);
	return 0;
}












