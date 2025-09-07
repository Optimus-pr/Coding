#include <iostream>
using namespace std;

class node{
private:
	int d;
	node * next;
public:
	node(int d)
	{
		this->d=d;
		next=0;
	}
};

class stack{
	node * top;
	int size;
public:
	stack(s){
		top=0;
		size=s;
	}

	void push(int x)
	{
		if(size==0)
		{
			cout<<"overflow";
			return;
		}
		node *t=new node(x);
		t->next=top;
		t=top;
		size--;
	}

	void pop(){
		if(top==0)
		{
			cout<<"empty"<<endl;
			return;
		}
		node *t=top->next;
		top=top->next;
		delete t;
	}

	int peek(){
		if(top==0)
		{
			cout<<"empty"<<endl;
			return -1;
		}
		return top->d;
	}

}

int main()
{

}