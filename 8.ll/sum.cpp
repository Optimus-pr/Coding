#include<bits/stdc++.h>
using namespace std;

class node
{
public:
	int data;
	node* next;

	node(int data){
		this->data=data;
		next=0;
	}
};


void insertrear(node * &head,int data)
{
	if(head==0)
	{
		head=new node(data);
		return;
	}
	node *t=head;
	while(t->next)
		t=t->next;
	node * nn=new node(data);
	t->next=nn;
}

void display(node * head)
{
	while(head)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;
}

void reverse(node * &head)
{
	node * r=0,*q=head,*p;
	while(q)
	{
		p=q->next;
		q->next=r;
		r=q;
		q=p;
	}
	head=r;
}

node * Sum(node * n1,node *n2)
{
	reverse(n1);
	reverse(n2);
	

	node * n3=0;
	int carry=0,sum=0;
	while(n1 && n2)
	{
		sum=(n1->data+n2->data+carry)%10;
		insertrear(n3,sum);
		carry=(n1->data+n2->data+carry)/10;
		n1=n1->next;
		n2=n2->next;
	}
	while(n1)
	{
		sum=(n1->data+carry)%10;
		insertrear(n3,sum);
		carry=(n1->data+carry)/10;
		n1=n1->next;
	}
	while(n2)
	{
		sum=(n2->data+carry)%10;
		insertrear(n3,sum);
		carry=(n2->data+carry)/10;
		n2=n2->next;
	}
	if(carry)
		insertrear(n3,carry);

	return n3;
}

int main()
{
	node* n1=0,*n2=0,*n3;
	insertrear(n1,9);
	insertrear(n1,9);
	insertrear(n1,9);
	insertrear(n1,9);
	insertrear(n1,9);
	display(n1);
	
	insertrear(n2,9);
	insertrear(n2,9);
	insertrear(n2,9);
	insertrear(n2,9);
	insertrear(n2,8);
	display(n2);

	n3=Sum(n1,n2);
	
	reverse(n3);
	
	display(n3);
	
}