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

int leftht(node *head)
{
	int cnt=0;
	while(head)
	{
		cnt++;
		head=head->llink;
	}
	return cnt;
}

int rightht(node *head)
{
	int cnt=0;
	while(head)
	{
		cnt++;
		head=head->rlink;
	}
	return cnt;
}

int cnt(node * head)
{
	if(head==0)
		return 0;

	int lt=leftht(head);
	int rt=rightht(head);

	if(lt==rt)
		return (1<<lt)-1;
	return 1+cnt(head->llink)+cnt(head->rlink);

}

int main()
{
	node *head=0;

	levelbuild(head);
	display(head);
	
	cout<<cnt(head);
	
	return 0;
}