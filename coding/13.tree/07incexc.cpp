#include<bits/stdc++.h>
using namespace std;

class node
{
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

node * levelbuild()
{
	queue<node *> q;
	int d;
	cin>>d;
	if(d==-1)
		return 0;
	node *head=new node(d);
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

void levelprint(node *head)
{
	queue<node *> q;
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

pair<int,int> incexc(node * head)
{
	pair<int,int> p,left,right;
	if(head==0)
	{
		p.first=0;
		p.second=0;
		return p;
	}
	left=incexc(head->llink);
	right=incexc(head->rlink);

	p.first=head->data+left.second+right.second;
	p.second=max(left.first,left.second)+max(right.first,right.second);

	return p;
}

int main()
{
	node *head=levelbuild();
	levelprint(head);
	pair<int,int> p=incexc(head);
	cout<<max(p.first,p.second);
	
	return 0;
}