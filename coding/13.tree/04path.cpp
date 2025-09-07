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

bool path(node * head,vector<int> &v,int target)
{
	if(head==0)
		return false;

	v.push_back(head->data);
	if(head->data==target)
		return true;
	if(path(head->llink,v,target))
		return true;

	if(path(head->rlink,v,target))
		return true;

	v.pop_back();
	return false;
}

int main()
{
	node *head1=0;

	levelbuild(head1);
	display(head1);
	
	int t;
	cin>>t;

	vector<int> a;

	if(path(head1,a,t))
	{
		for(auto &val:a)
			cout<<val<<" ";
		cout<<endl;
	}
	else
		cout<<"Path not found\n";
		
	return 0;
}