#include <stdio.h>
#include <iostream>
using namespace std;

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


class Stack{
	private:
		int num=0;
		int stack[Max]; 	
	public:
		void push(int a){
			num++;
			stack[num]=a;
		}
		void pop(){
			num--;
		}
		int gettop(){
			return stack[num];
		}
		int size(){
			return num;
		}
		bool isEmpty(){
			if(num==0)
				return true;
			else 
				return false;
		}
};

int tag[Max];
int tag2[Max];
Stack s;

int main(){
	int n,m;
	scanf("%d%d",&n,&m);

	int k=1;//k表示当前需要驶出的车厢 
	int j=1;
	int flag=0;
	for(int i=0;i<n;++i){
		int tmp;
		scanf("%d",&tmp);
		if(tmp==k){
			tag[j]=2;
			tag2[j]=tmp;
			++j;
			++k;
		}else if (tmp>k){
			s.push(tmp);
			tag[j]=1;
			tag2[j]=tmp;
			++j;
		}
		if(s.size()>m){
			flag=1;
			break;
		}
		while(!s.isEmpty()&&s.gettop()==k){
			tag2[j]=k;
			s.pop();
			tag[j]=0;
			++j;
			++k;
		}
	}
	if(flag==1)
		printf("No\n");
	else if(s.isEmpty()){
		for(int i=1;i<j;++i){
			if(tag[i]==2){
				printf("%d P\n",tag2[i]);
			}
			else if(tag[i]==1)
				printf("%d I\n",tag2[i]);
			else if(tag[i]==0)
				printf("%d O\n",tag2[i]);
		}
	}
	else
		printf("No\n");
	return 0;
}


















