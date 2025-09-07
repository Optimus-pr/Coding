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

void display(node * head)
{
	if(head==0)
		return;

	queue<node * >q;
	q.push(head);
	q.push(NULL);

	while(!q.empty())
	{
		node *t=q.front();
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

int width(node * root)
{
	queue<pair<node*,int> >q;
	q.push(make_pair(root,0));
	int mx=-999;

	while(!q.empty())
	{
		int n=q.size();
		int w=q.front().second;
		
		int first,last;

		for(int i=0;i<n;i++)
		{
			int id=q.front().second-w;
			node * t=q.front().first;
			q.pop();

			if(i==0)
				first=id;
			if(i==n-1)
				last=id;

			if(t->llink)
				q.push(make_pair(t->llink,2*id+1));
			if(t->rlink)
				q.push(make_pair(t->rlink,2*id+2));
		}
		mx=max(mx,last-first+1);
	}
	return mx;
}

int main()
{
	node *head=0;

	levelbuild(head);
	display(head);
		
	cout<<width(head);
	
	return 0;
}