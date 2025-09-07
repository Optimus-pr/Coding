#include<bits/stdc++.h>
using namespace std;

class node{
public:
	int data;
	node *llink;
	node *rlink;

	node(int data){
		this->data=data;
		llink=0;
		rlink=0;
	}
};


void levelbuild(node * &head)
{
	int d;
	cin>>d;

	queue<node*> q;

	if(d!=-1)
	{
		head=new node(d);
		q.push(head);
	}

	while(!q.empty())
	{
		node *t=q.front();
		q.pop();

		cin>>d;
		if(d!=-1)
		{
			t->llink=new node(d);
			q.push(t->llink);
		}

		cin>>d;
		if(d!=-1)
		{
			t->rlink=new node(d);
			q.push(t->rlink);
		}
	}
}

void iterflat(node * &root)
{
	node * cur=root;
	while(cur)
	{
		node * prev=cur->llink;
		if(prev)
		{
			while(prev->rlink)
				prev=prev->rlink;
			prev->rlink=cur->rlink;
			cur->rlink=cur->llink;
			cur->llink=NULL;
		}
		
		cur=cur->rlink;
	}
}

node *previous=NULL;

void recflat(node * head)
{
	if(head==0)
		return;
	recflat(head->rlink);
	recflat(head->llink);

	head->rlink=previous;
	head->llink=NULL;

	previous=head;
}

void display(node * head)
{
	while(head)
	{
		cout<<head->data<<" ";
		head=head->rlink;
	}
}

int main()
{
	node *head=0;
	levelbuild(head);
	recflat(head);
	display(head);
	
	return 0;
}