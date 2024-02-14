#include<bits/stdc++.h>
using namespace std;

class node
{
public:
	int data;
	node * llink;
	node * rlink;

	node(int d)
	{
		data=d;
		llink=0;
		rlink=0;
	}
};

node * levelbuild()
{
	queue<node*> q;
	int d;
	cin>>d;

	if(d==-1)
		return NULL;

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
	queue<node*> q;
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

bool checkfull(node * head)
{
	if(head==0)
		return true;
	if(head->llink==0 && head->rlink!=0)
		return false;
	if(head->rlink==0 && head->llink!=0)
		return false;
	return checkfull(head->llink)&&checkfull(head->rlink);
}

int main()
{
	node * root=levelbuild();
	levelprint(root);
	cout<<checkfull();
	return 0;
}