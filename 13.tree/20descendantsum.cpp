#include<bits/stdc++.h>
using namespace std;

class node 
{
public:
	int data;
	node *llink,*rlink;

	node(int data){
		this->data=data;
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
	return head;
}

void levelprint(node * head)
{
	queue<node*> q;
	q.push(head);
	q.push(NULL);

	while(!q.empty())
	{
		node *t=q.front();
		q.pop();

		if(t!=0)
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
			if(q.size()!=0)
				q.push(NULL);
		}
	}
}

int dessum(node * &head)
{
	if(head==0)
		return 0;
	int t=head->data;
	int lt=dessum(head->llink);
	int rt=dessum(head->rlink);

	if(lt==0 && rt==0)
		return head->data;

	head->data=lt+rt;

	return t+head->data;
}

int main()
{
	node * head=levelbuild();
	dessum(head);
	levelprint(head);
	return 0;
}