//the same code can be modified to burn the tree and time taken to do the same can be found out

#include<bits/stdc++.h>
using namespace std;

class node
{
public:
	int data;
	node * llink;
	node * rlink;

	node(int d)
	{
		data=d;
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

node * levelprint(node * head)
{
	queue<node*> q;
	node *ans;
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
			if(t->data==2)
				ans=t;
			if(t->llink)
				q.push(t->llink);
			if(t->rlink)
				q.push(t->rlink);
		}
	}
	return ans;
}

void computeparents(node * root,unordered_map<node*,node*> &u)
{
	queue<node*> q;
	q.push(root);

	while(!q.empty())
	{
		node * t=q.front();
		q.pop();

		if(t->llink)
		{
			q.push(t->llink);
			u[t->llink]=t;
		}

		if(t->rlink)
		{
			q.push(t->rlink);
			u[t->rlink]=t;
		}
	}
}

vector<int> printatk(node *root,node * t,int k)
{
	queue<node* > q;
	unordered_map<node *,node *> u;
	unordered_map<node *,bool> vis;

	computeparents(root,u);

	q.push(t);
	vis[t]=true;

	int cur=0;

	while(!q.empty())
	{
		int n=q.size();
		if(cur++==k)
			break;

		for(int i=0;i<n;i++)
		{
			node * t=q.front();
			q.pop();

			if(t->llink && vis.find(t->llink)==vis.end())
			{
				q.push(t->llink);
				vis[t->llink]=true;
			}

			if(t->rlink && vis.find(t->rlink)==vis.end())
			{
				q.push(t->rlink);
				vis[t->rlink]=true;
			}

			if(u.find(t)!=u.end() && u[t] && vis.find(u[t])==vis.end())//here we need to check for  u[t] as eventhough t doesn't have parent i.e null but the entry will be there in the map so !=m.end() but when we try to find u[t] i.e u[NULL] then we will get seg fault so..
				
			{
				q.push(u[t]);
				vis[u[t]]=true;
			}
		}
	}

	vector<int> v;

	while(!q.empty())
	{
		node *t=q.front();
		q.pop();

		v.push_back(t->data);
	}

	return v;

}

int main()
{
	node * root=levelbuild();
	node * t=levelprint(root);
	vector<int> v=printatk(root,t,2);

	for(auto &val:v)
		cout<<val<<" ";
	cout<<endl;

	return 0;
}