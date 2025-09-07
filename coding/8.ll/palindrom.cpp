#include<bits/stdc++.h>
using namespace std;

class node{
public:
	int data;
	node* next;

	node(int data){
		this->data=data;
		next=0;
	}
};

void display(node * head)
{
	while(head)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;
}

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
	node *nn=new node(data);
	t->next=nn;
}

node* rev(node * head)
{
	node *q=head,*r=0,*p;

	while(q)
	{
		p=q->next;
		q->next=r;
		r=q;
		q=p;
	}
	return r;
}

node * recrev(node * &head)
{
	if(head==0 || head->next==0)
		return head;

	node * shead=recrev(head->next);
	head->next->next=head;
	head->next=0;

	return shead;

}

bool ispalin(node * &head)
{
	node * s=head,*f=head;

	while(f && f->next)
	{
		s=s->next;
		f=f->next->next;
	}

	
	s->next=rev(s->next);
	
	s=s->next;
	node * s1=head;
	while(s)
	{
		if(s->data==s1->data)
		{
			s=s->next;
			s1=s1->next;
		}
		else
			return false;
	}
	return true;
}

int main()
{
	node * head=0;

	insertrear(head,1);
	insertrear(head,1);
	insertrear(head,2);
	insertrear(head,1);
	insertrear(head,1);
	insertrear(head,1);
	display(head);

	cout<<ispalin(head);
}