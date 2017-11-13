#include <stdio.h>
#include <iostream>

const long Max= 300005;

template <class T>
class Stack{
	private:
		int num=0;
		T stack[Max]; 	
	public:
		void push(T a){
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

struct Point{
	int x;
	int y;
};
