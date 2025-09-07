#include<bits/stdc++.h>
using namespace std;

class node{
public:
	int data;
	node *llink;
	node *rlink;

	node(int data)
	{
		this->data=data;
		llink=0;
		rlink=0;
	}
};

node *levelcreate()
{
	int d;
	cin>>d;
	queue<node *> q;
	node *head=new node(d);
	q.push(head);

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
	return head;

}	

void levelprint(node * head)
{
	if(head==0)
		return;
	queue<node *> q;
	q.push(head);
	q.push(NULL);

	while(!q.empty())
	{
		node *t =q.front();
		q.pop();

		if(t==NULL)
		{
			cout<<endl;
			if(!q.empty())
				q.push(NULL);
		}
		else
		{
			cout<<t->data<<" ";
			if(t->llink)
				q.push(t->llink);
			if(t->rlink)
				q.push(t->rlink);
		}
	}
}

int height(node * head)
{
	if(head==0)
		return 0;
	return height(head->llink)+height(head->rlink)+1;
}

int main()
{
	node *head=levelcreate();
	levelprint(head);
	cout<<height(head);
	return 0;
}