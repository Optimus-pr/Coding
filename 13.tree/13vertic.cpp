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

vector<int> verticalOrder(Node *root)
{
     queue<pair<Node *,int> > q;
     q.push({root,0});
     map<int,vector<int> > m;
     
     while(!q.empty())
     {
         Node *t=q.front().first;
         int v=q.front().second;
         q.pop();
         
         m[v].push_back(t->data);
         
         if(t->left)
             q.push({t->left,v-1});
         if(t->right)
             q.push({t->right,v+1});
     }
     
     vector<int> res;
     
     for(auto &val:m)
     {
         for(auto &info:val.second)
             res.push_back(info);
     }
     return res
 }
int main()
{
	node *root=levelbuild();
	levelprint(root);
	vector<vector<int> > ans=vertical(root);

	for(auto &val:ans)
	{
		for(auto &info:val)
		{
			cout<<info<<" ";
		}
		cout<<endl;
	}
	return 0;
}