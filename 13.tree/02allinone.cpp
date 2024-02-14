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

void allinone(node * head)
{
	vector<int> pre,post,in;
	stack<pair<node*,int> > s;
	s.push(make_pair(head,1));

	while(!s.empty())
	{
		auto p=s.top();
		s.pop();

		if(p.second==1)
		{
			pre.push_back(p.first->data);
			p.second++;
			s.push(p);
			if(p.first->llink)
				s.push(make_pair(p.first->llink,1));
		}
		else if(p.second==2)
		{
			in.push_back(p.first->data);
			p.second++;
			s.push(p);
			if(p.first->rlink)
				s.push(make_pair(p.first->rlink,1));
		}
		else
			post.push_back(p.first->data);
	}

	for(auto &val:pre)
		cout<<val<<" ";
	cout<<endl;

	for(auto &val:in)
		cout<<val<<" ";
	cout<<endl;

	for(auto &val:post)
		cout<<val<<" ";
	cout<<endl;
}

int main()
{
	node *head=0;

	levelbuild(head);
	// display(head);
	allinone(head);
	return 0;
}