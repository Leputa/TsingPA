#include <stdio.h>

const int Max=10000005;

const int MAXBUFFER = 1 << 20;

struct fastio {
	char inbuf[MAXBUFFER];
	char outbuf[MAXBUFFER];
	fastio() {
		setvbuf(stdin, inbuf, _IOFBF, MAXBUFFER);
		setvbuf(stdout, outbuf, _IOFBF, MAXBUFFER);
	}
}io;

class Employee{
	public :
		int code;
		int num;
		Employee(){
			code=-1;
			num=0;
		}
};

class Company{
	private:
		int num=0;
		int tag[Max]={0};
	
	public:
		Employee employee[Max];
		
		bool isLogIn(int id){
			if(employee[id].code==-1)
				return false;
			else return true;
		}
		
		void LogIn(int id,int code){
			if(!isLogIn(id)){       
				num++;
				tag[num]=id;
				employee[id].num=num;
			}
			else{
				//tag[num]=id; //这儿有问题 ，必须找到之前的num，而非现在的.... 
				tag[employee[id].num]=id;	
			}
			employee[id].code=code;
						
		}
		void LogOut(int id){
			if(isLogIn(id)){
				employee[id].code=-1;
				num--;
			}
		}
		
		void close(){
			for(int i=1;i<=num;i++){
				int id=tag[i];
				employee[id].code=-1;
				//employee[id].id=0;
			}
			num=0;
		}
		
		int getNum(){
			return num;
		}
		int Query(int id){
			return employee[id].code;
		}
};

Company company;

int main(){
	int n;
	int m;
	int cnt=0;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		char tmp;
		
		while (scanf("%c", &tmp) && tmp!= 'I' && tmp!= 'O'&& tmp!= 'C'&& tmp!= 'N'&& tmp!= 'Q');//吸收空格回车

		if(tmp=='I'){
			int id;
			int code;
			scanf("%d %d",&id,&code);
			company.LogIn(id,code);
		}
		
		if(tmp=='O'){
			int id;
			scanf("%d",&id);
			company.LogOut(id);
		}
		if(tmp=='C')
			company.close();
		if(tmp=='N'){
			cnt+=company.getNum();
		}

		if(tmp=='Q'){
			int id;
			scanf("%d",&id);
			cnt+=company.Query(id);
		}
	}
	printf("%d",cnt);
	return 0;
}


