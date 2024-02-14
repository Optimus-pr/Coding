#include<bits/stdc++.h>
using namespace std;

class node{
public:
	int data;
	node * llink,*rlink;

	node(int d)
	{
		data=d;
		llink=0;
		rlink=0;
	}
};

class hdnode{
public:
	int h;
	int d;
};

node * buildtree(){
	int d;
	cin>>d;

	if(d==-1)
		return 0;

	node * n=new node(d);
	n->llink=buildtree();
	n->rlink=buildtree();

	return n;
}

node * levelbuildtree(){
	int d;
	cin>>d;

	node * n=new node(d);

	queue<node *> q;
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

		cin>>d;
		if(d!=-1)
		{
			t->rlink=new node(d);
			q.push(t->rlink);
		}
	}
	return n;
}

void printlevel(node * r)
{
	queue<node *> q;
	q.push(r);
	q.push(NULL);

	while(!q.empty())
	{
		node *d=q.front();
		q.pop();

		if(d==0)
		{
			cout<<endl;
			if(!q.empty())
				q.push(NULL);
		}
		else
		{
			cout<<d->data<<" ";
			if(d->llink)
				q.push(d->llink);
			if(d->rlink)
				q.push(d->rlink);
		}
	}
}

int ht(node *root)
{
	if(root==0)
		return 0;
	int h1=ht(root->llink);
	int h2=ht(root->rlink);

	return 1+max(h1,h2);
}

int diameter(node * root)
{
	if(root==0)
		return 0;

	int d1=ht(root->llink)+ht(root->rlink);
	int d2=diameter(root->llink);
	int d3=diameter(root->rlink);

	return max(max(d1,d2),d3);
}

hdnode optidiameter(node * root)
{
	hdnode p;

	if(root==0)
	{
		p.h=p.d=0;
		return p;
	}

	hdnode left=optidiameter(root->llink);
	hdnode right=optidiameter(root->rlink);

	p.h=max(left.h,right.h)+1;

	int d1=left.h+right.h;
	int d2=left.d;
	int d3=right.d;

	p.d=max(d1,max(d2,d3));
	return p;
}

int main()
{
	//node * root=prebuildtree();
	node * root=levelbuildtree();
	cout<<"hi";
	//printlevel(root);
	hdnode nd=optidiameter(root);
	cout<<nd.h<<" "<<nd.d<<endl;
	return 0;
}