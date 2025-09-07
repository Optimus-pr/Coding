#include<bits/stdc++.h>
using namespace std;

class node{
public:
	int data;
	node * next;

	node(int data)
	{
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
	node * t=head;
	while(t->next)
		t=t->next;
	node *nn=new node(data);
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

node * revk(node * head,int k)
{
	if(k==0)
		return head;
	int cnt=0;
	node * q=head,*r=0,*p;

	while(cnt!=k && q)
	{
		p=q->next;
		q->next=r;
		r=q;
		q=p;
		cnt++;
	}
	if(q)
		head->next=revk(q,k);
	return r;
}

int main()
{

	node * head=0;

	insertrear(head,1);
	insertrear(head,2);
	insertrear(head,3);
	insertrear(head,4);
	insertrear(head,5);
	insertrear(head,6);
	insertrear(head,7);
	insertrear(head,8);

	node * h=revk(head,1);
	display(h);
}