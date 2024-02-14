#include<bits/stdc++.h>
using namespace std;

class node{
public:
	int data;
	node * llink;
	node *rlink;

	node(int data)
	{
		this->data=data;
		llink=0;
		rlink=0;
	}
};
	
void levelbuild(node * &head)
{
	int d;
	cin>>d;
	queue<node *>q;

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
		if(t==0)
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

void printlevel(node * head,int k)
{
	if(head==0)
		return;

	if(k==0)
	{
		cout<<head->data<<" ";
		return;
	}
	printlevel(head->llink,k-1);
	printlevel(head->rlink,k-1);

}

int main()
{
	node * head=0;

	levelbuild(head);
	display(head);
	printlevel(head,1);
	return 0;
}