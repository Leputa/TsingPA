/*
#include <stdio.h>

const int Max=300005;

const int MAXBUFFER = 1 << 20;

struct fastio {
	char inbuf[MAXBUFFER];
	char outbuf[MAXBUFFER];
	fastio() {
		setvbuf(stdin, inbuf, _IOFBF, MAXBUFFER);
		setvbuf(stdout, outbuf, _IOFBF, MAXBUFFER);
	}
}io;


struct Village{
	int xi;
	int wi;	
}village[Max];


void qsort(Village village[], int lo, int hi)
{
	if (lo < hi)
	{
		int i = lo, j = hi;
		Village tmp;
		tmp.xi = village[i].xi;
		tmp.wi = village[i].wi;
		int key = village[i].xi;

		while (i < j)
		{
			while (i < j && key < village[j].xi) 
				j--;			
			village[i].xi = village[j].xi;
			village[i].wi = village[j].wi;
			while (i < j && village[i].xi < key)
				i++;
			village[j].xi = village[i].xi;
			village[j].wi = village[i].wi;
		}

		village[i].xi = tmp.xi;
		village[i].wi = tmp.wi;
		
		qsort(village, lo, i - 1);
		qsort(village, i + 1, hi);
	}
}


int main(){
	int n;
	scanf("%d",&n);
	
	for(int i=0;i<n;i++)
		scanf("%d %d",&village[i].xi,&village[i].wi);
	qsort(village,0,n-1);
	
	int left=0;
	int right=0;
	
	for(int i=0;i<n;i++)
		right+=village[i].wi;
	int j;
	long long sum=0;
	for(j=0;j<n;j++){
		left+=village[j].wi;
		right-=village[j].wi;
		if(left>=right)
			break;
	}
	printf("%d\n",village[j].xi);
	for(int i=0;i<n;i++)
		if(i<=j)
			sum+=village[i].wi*(village[j].xi-village[i].xi);
		else 
			sum+=village[i].wi*(village[j].xi-village[i].xi);
	printf("%d\n",sum);
	return 0;
}
*/

//排序真是蠢哭了

#include <stdio.h>

long long W[32770]={0}; //di为下标 

const int MAXBUFFER = 1 << 20;

struct fastio {
	char inbuf[MAXBUFFER];
	char outbuf[MAXBUFFER];
	fastio() {
		setvbuf(stdin, inbuf, _IOFBF, MAXBUFFER);
		setvbuf(stdout, outbuf, _IOFBF, MAXBUFFER);
	}
}io;

int main(){
	int n;
	scanf("%d",&n);
	long long left=0,right=0;
	for(int i=0;i<n;i++){
		int xi,wi;
		scanf("%d %d",&xi,&wi);
		W[xi]+=wi;
		right+=wi;
	}
	int i;
	for( i=0;i<32770;i++){
		left+=W[i];
		right-=W[i];
		if(left>=right)
			break;
	}
	printf("%d\n",i);
	
	long long sum=0;
	for(int j=0;j<32770;j++){
		if(W[j]!=0){
			 int d=(j>=i)?j-i:i-j;
			 sum+=W[j]*d;
		}
	}
	printf("%lld\n",sum);
	return 0;
}


