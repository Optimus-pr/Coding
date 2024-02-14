#include<bits/stdc++.h>
using namespace std;

class node
{
public:
	int d;
	node *llink;
	node *rlink;

	node(int d)
	{
		this->d=d;
		llink=0;
		rlink=0;
	}
};

class hrnode
{
public:
	int ht;
	int diameter;
};

hrnode optdiameter(node * head)
{
	hrnode p;
	if(head==0)
	{
		p.ht=0;p.diameter=0;
		return p;
	}

	hrnode left=optdiameter(head->llink);
	hrnode right=optdiameter(head->rlink);
	p.ht=max(left.ht,right.ht)+1;

	int d1=left.ht+right.ht;
	int d2=left.diameter;
	int d3=right.diameter;

	p.diameter=max(d1,max(d2,d3));
	return p;
}

node * levelbuild()
{
	int d;
	cin>>d;

	queue<node*> q;
	node * n=new node(d);
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
			t->llink=NULL;
		cin>>d;
		if(d!=-1)
		{
			t->rlink=new node(d);
			q.push(t->rlink);
		}
		else
			t->rlink=NULL;
	}
	return n;
}

void levelprint(node * h)
{
	queue<node*> q;
	q.push(h);
	q.push(NULL);

	while(!q.empty())
	{
		node * t=q.front();
		q.pop();
		if(t!=NULL)
		{
			cout<<t->d<<" ";
			if(t->llink)
				q.push(t->llink);
			if(t->rlink)
				q.push(t->rlink);
		}
		else
		{
			cout<<endl;
			if(!q.empty())
				q.push(NULL);
		}
	}
}

int main()
{
	node * head=levelbuild();
	levelprint(head);
	cout<<optdiameter(head).diameter;
	return 0;
}