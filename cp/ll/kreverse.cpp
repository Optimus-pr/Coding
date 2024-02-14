#include<bits/stdc++.h>
using namespace std;

class node
{
public:
	int data;
	node * next;
	node(int data)
	{
		this->data=data;
		next=NULL;
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
	if(head==0)
		return;
	while(head)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;
}

node * kreverse(node *head,int k)
{
	int cnt=0;
	node *r=0,*q=head,*p;
	while(q && cnt<k)
	{
		p=q->next;
		q->next=r;
		r=q;
		q=p;
		cnt++;
	}
	if(q)//here we can also use p instead of q as both will be pointing the same node;
		head->next=kreverse(q,k);
	return r;
}

int main()
{
	node *head=0;

	insertend(head,1);
	insertend(head,2);
	insertend(head,3);
	// insertend(head,4);
	// insertend(head,5);
	// insertend(head,6);
	// insertend(head,7);
	// insertend(head,8);
	// insertend(head,9);
	// insertend(head,10);
	// insertend(head,11);

	head=kreverse(head,2);

	display(head);
	return 0;
}