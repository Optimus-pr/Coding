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

node * levelbuild()
{
	queue<node*> q;

	int d;
	cin>>d;

	if(d==-1)
		return NULL;

	node *head =new node(d);
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

vector<int> topview(node * root)
{
	queue<pair<node *,int> > q;
	q.push(make_pair(root,0));
	map<int,int> m;
	vector<int> v;
	
	while(!q.empty())
	{
		node *t=q.front().first;
		int verti=q.front().second;
		// if(m.find(verti)==m.end()) if we comment this then it will be bottom view
			m[verti]=t->data;
		q.pop();

		if(t->llink)
			q.push(make_pair(t->llink,verti-1));
		if(t->rlink)
			q.push(make_pair(t->rlink,verti+1));
	}

	for(auto val:m)
		v.push_back(val.second);
	return v;
}

int main()
{
	node *root=levelbuild();
	levelprint(root);
	vector<int> v=topview(root);
	for(auto val:v)
		cout<<val<<" ";
	cout<<endl;
	return 0;
}