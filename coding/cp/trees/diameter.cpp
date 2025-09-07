#include<bits/stdc++.h>
using namespace std;

class node
{
public:
	int d;
	node * llink;
	node * rlink;

	node(int d)
	{
		this->d=d;
		llink=NULL;
		rlink=NULL;
	}
};

node * levelcreate()
{
	queue<node *> q;
	int d;
	cin>>d;

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
	return n;
}

void levelprint(node * head)
{
	queue<node*> q;
	q.push(head);
	q.push(NULL);

	while(!q.empty())
	{
		node * t=q.front();
		q.pop();
		if(t)
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

int ht(node * head)
{
	if(head==0)
		return 0;
	int h1=ht(head->llink);
	int h2=ht(head->rlink);
	return 1+max(h1,h2);
}

int diameter(node * head)
{
	if(head==0)
		return 0;
	int d1=ht(head->llink)+ht(head->rlink);
	int d2=diameter(head->llink);
	int d3=diameter(head->rlink);

	return max(d1,max(d2,d3));
}

int main()
{
	node * head=levelcreate();
	levelprint(head);
	cout<<diameter(head);
	return 0;
}