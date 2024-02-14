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

vector<vector<int> > zigzag(node * head)
{
	queue<node *> q;
	q.push(head);

	int leftToright=1;
	vector<vector<int> > v;

	while(!q.empty())
	{
		int size=q.size();
		vector<int> row(size);
		
		for(int i=0;i<size;i++)
		{
			node *t=q.front();
			q.pop();

			int index=leftToright?i:size-i-1;
			row[index]=t->data;

			if(t->llink)
				q.push(t->llink);
			if(t->rlink)
				q.push(t->rlink);
		}
		leftToright=!leftToright;
		v.push_back(row);

	}
	return v;

}


int main()
{
	node *head1=0;

	levelbuild(head1);
	display(head1);
	
	vector<vector<int> > v=zigzag(head1);

	for(auto &val:v)
		for(auto &info:val)
			cout<<info<<" ";
		cout<<endl;

	
	return 0;
}