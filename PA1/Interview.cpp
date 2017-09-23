#include <stdio.h>
#include <malloc.h>

const int MAXBUFFER = 1 << 20;

struct fastio {
	char inbuf[MAXBUFFER];
	char outbuf[MAXBUFFER];
	fastio() {
		setvbuf(stdin, inbuf, _IOFBF, MAXBUFFER);
		setvbuf(stdout, outbuf, _IOFBF, MAXBUFFER);
	}
}io;

struct Node{
	Node *left;   //逆时针 
	Node *right;  //顺时针 
	int id;
};

int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	
	int id;
	scanf("%d",&id);
	Node *firstNode=(Node*)malloc(sizeof(Node));
	firstNode->id=id;
	firstNode->left=firstNode;
	firstNode->right=firstNode;
	Node *preNode=firstNode;
	
	for(int i=1;i<n;i++){
		scanf("%d",&id);
		Node *thisNode=(Node*)malloc(sizeof(Node));
		thisNode->id=id;
		Node *tmpNode=preNode;
		int cnt=0;       //已经走过了第一人 
		while(cnt!=m){
			tmpNode=tmpNode->left;
			cnt++;  
		}
		thisNode->left=tmpNode;
		thisNode->right=tmpNode->right;
		tmpNode->right->left=thisNode;
		tmpNode->right=thisNode;
		preNode=thisNode;
	}
	Node *tmpNode=preNode;
	printf("%d ",tmpNode->id);
	tmpNode=tmpNode->right;
	while(tmpNode!=preNode){
		printf("%d ",tmpNode->id);
		tmpNode=tmpNode->right;
	}
	return 0;
}
