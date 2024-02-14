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

void leftview(vector<int> &v,node * root,int level)
{
	if(root==NULL)
		return;
	
	if(level==v.size())
		v.push_back(root->data);
	
	leftview(v,root->rlink,level+1);//interchanging these 2 lines will give right view
	leftview(v,root->llink,level+1);
	
}

int main()
{
	node *head=0;
	levelbuild(head);
	display(head);

	vector<int> v;

	leftview(v,head,0);

	for(auto &val:v)
		cout<<val<<" ";
	cout<<endl;

	return 0;
}