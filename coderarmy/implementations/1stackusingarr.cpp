// stack is implemented via deque
// when we had vector why we need stack even vector will have pushback and popback operations but to save memory i.e vector upon pushing the capacity will become 2 times of that of earlier so ..

#include <iostream>
using namespace std;

class stack{
private:
	int *a;
	int top;
	int size;
public:
	stack(int s)
	{
		a=new int[s];
		top=-1;
		size=s;
	}

	void push(int x)
	{
		if(top==size-1)
		{
			cout<<"overflow"<<endl;
			return;
		}
		a[top++]=x;
	}

	void pop(){
		if(top==-1){
			cout<<"underflow"<<endl;
			return;
		}
		top--;
	}

	int peek(){
		if(top==-1)
		{
			cout<<"empty"<<endl;
			return -1;
		}
		return a[top];
	}

	int isSize(){
		return top+1;
	}

};

int main()
{
	stack s(5);
	s.push(1);
	cout<<s.peek();
	cout<<s.isSize();
	cout<<s.pop();
	return 0;
}