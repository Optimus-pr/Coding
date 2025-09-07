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

bool isleaf(node * head)
{
	if(head->llink==0 && head->rlink==0)
		return true;
	return false;
}

void leftboundary(node * head,vector<int> &v)
{
	node *cur=head->llink;
	while(cur)
	{
		if(!isleaf(cur))
			v.push_back(cur->data);
		if(cur->llink)
			cur=cur->llink;
		else
			cur=cur->rlink;
	}
}

void addleaves(node *head,vector<int> &v)
{
	if(head==0)
		return;

	if(isleaf(head))
	{
		v.push_back(head->data);
		return;
	}

	addleaves(head->llink,v);
	addleaves(head->rlink,v);
}

void rightboundary(node *head,vector<int> &v)
{
	node *cur=head->rlink;
	vector<int> temp;
	while(cur)
	{
		if(!isleaf(cur))
			temp.push_back(cur->data);
		if(cur->rlink)
			cur=cur->rlink;
		else
			cur=cur->llink;
	}
	for(int i=temp.size()-1;i>=0;i--)
		v.push_back(temp[i]);
}

int main()
{
	node *head=0;
	vector<int> v;
	levelbuild(head);
	display(head);
	if(!isleaf(head))v.push_back(head->data);
	leftboundary(head,v);
	addleaves(head,v);
	rightboundary(head,v);

	for(auto &val:v)
		cout<<val<<" ";
	cout<<endl;

	return 0;
}