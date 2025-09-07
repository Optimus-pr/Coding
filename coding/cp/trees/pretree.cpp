#include<bits/stdc++.h>
using namespace std;

class node
{
public:
	int d;
	node * llink;
	node * rlink;

	node(int d){
		this->d=d;
		llink=0;
		rlink=0;
	}
};

node * precreatetree()
{
	int d;
	cin>>d;

	if(d==-1)
		return NULL;

	node * n=new node(d);
	n->llink=precreatetree();
	n->rlink=precreatetree();

	return n;
}

node * levelcreatetree()
{
	int d;
	cin>>d;
	queue<node *> q;
	node * n=new node(d);
	node * h=n;
	q.push(n);
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
		else
			t->llink=0;
		cin>>d;
		if(d!=-1)
		{
			t->rlink=new node(d);
			q.push(t->rlink);
		}
		else
			t->rlink=0;
	}
	return h;
}

void leveldisplay(node * h)
{
	queue<node *> q;
	q.push(h);
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
			if(t->llink)
				q.push(t->llink);
			if(t->rlink)
				q.push(t->rlink);
			cout<<t->d<<" ";
		}
	}
}

int main()
{
	node *head=levelcreatetree();
	leveldisplay(head);
	return 0;
}