#include<bits/stdc++.h>
using namespace std;

class node
{
public:
	int data;
	node * llink;
	node * rlink;

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

	queue<node *> q;

	if(d!=-1)
	{
		head=new node(d);
		q.push(head);
	}
	else
		return;	

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

		if(t!=NULL)
		{
			cout<<t->data<<" ";
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

pair<int,int> maxsubsum(node * head)
{
	pair<int,int> p;

	if(head==0)
	{
		p.first=0;
		p.second=0;
		return p;
	}

	pair<int,int> lt=maxsubsum(head->llink);
	pair<int,int> rt=maxsubsum(head->rlink);

	p.first=head->data+lt.second+rt.second;
	p.second=max(lt.first,lt.second)+max(rt.first,rt.second);

	return p;
}

int main()
{
	node * head=0;

	levelbuild(head);
	display(head);
	pair<int,int> p= maxsubsum(head);
	cout<<max(p.first,p.second);
	return 0;
}	