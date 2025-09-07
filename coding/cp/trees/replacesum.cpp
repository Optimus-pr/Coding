#include<bits/stdc++.h>
using namespace std;

class node
{
public:
	int data;
	node * llink;
	node * rlink;

	node(int data)
	{
		this->data=data;
		llink=0;
		rlink=0;
	}
};

node * levelcreate()
{
	
	queue<node *> q;
	int d;
	cin>>d;
	node * head=new node(d);
	q.push(head);

	while(!q.empty())
	{
		node * t=q.front();
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
	queue<node *> q;
	if(head==0)
	{
		cout<<"Empty"<<endl;
		return;
	}
	q.push(head);
	q.push(NULL);

	while(!q.empty())
	{
		node * t=q.front();
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

void dfs(node * &head)
{
	if(head==0)
		return;
	dfs(head->llink);
	dfs(head->rlink);
	if(head->llink)
		head->data+=head->llink->data;
	if(head->rlink)
		head->data+=head->rlink->data;
}

int main()
{
	node *head=levelcreate();
	levelprint(head);
	dfs(head);
	levelprint(head);
	return 0;
}