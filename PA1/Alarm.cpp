<<<<<<< HEAD
#include <stdio.h>
#include <math.h>



const int Max=200005;

const int MAXBUFFER = 1 << 20;

struct fastio {
	char inbuf[MAXBUFFER];
	char outbuf[MAXBUFFER];
	fastio() {
		setvbuf(stdin, inbuf, _IOFBF, MAXBUFFER);
		setvbuf(stdout, outbuf, _IOFBF, MAXBUFFER);
	}
}io;

struct Line{
	unsigned int x;
	unsigned int y;
}lines[Max];

struct Points{
	unsigned int x;
	unsigned int y;
}points[Max];

int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	for (int i=0;i<n;i++)
		scanf("%d %d",&lines[i].x,&lines[i].y);
	for (int i=0;i<m;i++)
		scanf("%d %d",&points[i].x,&points[i].y);
	
	double tmp;
	for (int i=0;i<m;i++){
		//感觉这里可以优化为二分查找 
		int tag=0;
		int low=0,high=n-1;
		int mid;
		while(low<=high){
			mid=(low+high)/2;
			tmp=points[i].x/(double)lines[mid].x+points[i].y/(double)lines[mid].y;
			if(tmp==1){  //判断在线上 
				printf("%d\n",mid+1);
				tag=1;
				break;
			}
			if(tmp<1){           
				double newtmp=points[i].x/(double)lines[mid-1].x+points[i].y/(double)lines[mid-1].y;
				if(newtmp>=1){
					printf("%d\n",mid);
					tag=1;
					break;
				}
			    else
			    	high=mid-1;
			}
			else if(tmp>1)
				low=mid+1;
	
		}
	    /*for (int j=0;j<n;j++){
			 tmp=points[i].x/(double)lines[j].x+points[i].y/(double)lines[j].y;
			if (tmp<1){
				printf("%d\n",j);
				tag=1;
				break;
			}
		}*/
		if(tag==0)
			printf("%d\n",n);
	}
	return 0;
}
=======
#include <stdio.h>
#include <math.h>



const int Max=200005;

const int MAXBUFFER = 1 << 20;

struct fastio {
	char inbuf[MAXBUFFER];
	char outbuf[MAXBUFFER];
	fastio() {
		setvbuf(stdin, inbuf, _IOFBF, MAXBUFFER);
		setvbuf(stdout, outbuf, _IOFBF, MAXBUFFER);
	}
}io;

struct Line{
	unsigned int x;
	unsigned int y;
}lines[Max];

struct Points{
	unsigned int x;
	unsigned int y;
}points[Max];

int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	for (int i=0;i<n;i++)
		scanf("%d %d",&lines[i].x,&lines[i].y);
	for (int i=0;i<m;i++)
		scanf("%d %d",&points[i].x,&points[i].y);
	
	double tmp;
	for (int i=0;i<m;i++){
		//感觉这里可以优化为二分查找 
		int tag=0;
		int low=0,high=n-1;
		int mid;
		while(low<=high){
			mid=(low+high)/2;
			tmp=points[i].x/(double)lines[mid].x+points[i].y/(double)lines[mid].y;
			if(tmp==1){  //判断在线上 
				printf("%d\n",mid+1);
				tag=1;
				break;
			}
			if(tmp<1){           
				double newtmp=points[i].x/(double)lines[mid-1].x+points[i].y/(double)lines[mid-1].y;
				if(newtmp>=1){
					printf("%d\n",mid);
					tag=1;
					break;
				}
			    else
			    	high=mid-1;
			}
			else if(tmp>1)
				low=mid+1;
	
		}
	    /*for (int j=0;j<n;j++){
			 tmp=points[i].x/(double)lines[j].x+points[i].y/(double)lines[j].y;
			if (tmp<1){
				printf("%d\n",j);
				tag=1;
				break;
			}
		}*/
		if(tag==0)
			printf("%d\n",n);
	}
	return 0;
}
>>>>>>> 28d61c6ec7887c8e84d2c80add87fce7c4e39f78
