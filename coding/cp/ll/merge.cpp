#include<bits/stdc++.h>
using namespace std;

class node
{
public:
	int data;
	node *next;
	node(int data){
		this->data=data;
		next=0;
	}
};

void insertend(node * &head,int data)
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

void display(node *head)
{
	while(head)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;
}

node * merge(node * h1,node *h2)
{
	node *p=h1,*q=h2,*temp=p;

	if(p->data>q->data)
	{
		h1=q;
		temp=q;
	}

	while(p && q)
	{
		if(p->data<q->data)
		{
			p=p->next;
			temp->next=q;
			temp=q;
		}
		else
		{
			q=q->next;
			temp->next=p;
			temp=p;
		}
	}
	
	if(p)
		temp->next=q;
	else if(q) 
		temp->next=p;

	
	return h1;
}

int main()
{
	node *h1=0;
	node *h2=0;

	insertend(h1,2);
	insertend(h1,4);
	insertend(h1,6);

	insertend(h2,1);
	insertend(h2,3);
	insertend(h2,5);
	insertend(h2,7);

	h1=merge(h1,h2);

	display(h1);

	return 0;
}