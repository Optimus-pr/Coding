#include<bits/stdc++.h>
using namespace std;

class node
{
public:
	int data;
	node * left;
	node * right;

	node(int d)
	{
		data=d;
		left=0;
		right=0;
	}
};

map<node*,node*> m;
map<node*,int> vis;

node * levelbuild()
{
	queue<node *> q;
	int d;
	cin>>d;

	node * head=new node(d);
	q.push(head);

	while(!q.empty())
	{
		node *t=q.front();
		q.pop();

		cin>>d;
		if(d!=-1)
		{
			t->left=new node(d);
			q.push(t->left);
		}

		cin>>d;
		if(d!=-1)
		{
			t->right=new node(d);
			q.push(t->right);
		}
	}
	return head;
}

void levelprint(node * head)
{
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
			if(t->left)
				q.push(t->left);
			if(t->right)
				q.push(t->right);
		}
	}
}

node * compute(node * head,int d)
{
	queue<node *> q;

	q.push(head);
	node * temp=NULL;
	m[head]=NULL;

	while(!q.empty())
	{
		node *t=q.front();
		q.pop();

		if(t->data==d)
		{
		    temp=t;
		   
		}
			
		if(t->left)
		{
		    q.push(t->left);
		    m[t->left]=t;
		}
		
		if(t->right)
		{
		    q.push(t->right);
		    m[t->right]=t;
		}
	}
	
	return temp;
}

int sumatK(node *head,int k)
{
	queue<pair<node *,int> > q;
	q.push(make_pair(head,k));
	vis[head]=1;

	int sum=0;

	while(!q.empty())
	{
		node * t=q.front().first;
	
		int d=q.front().second;
		q.pop();
		
       cout<<t->data<<" "<<d<<endl;
        
		if(d==0)
		{
		    cout<<"hi";
		    sum+=t->data;

		}
			
		if(t->left && vis.find(t->left)==vis.end())
		{
		    vis[t->left]=1;
		    q.push(make_pair(t->left,d-1));
		}
			

		if(t->right && vis.find(t->right)==vis.end())
	    {
			q.push(make_pair(t->right,d-1));
			vis[t->right]=1;
	    }

		if(m.find(t)!=0 && vis.find(m[t])==vis.end())
		{
			q.push(make_pair(m[t],d-1));
			vis[m[t]]=1;
		}

	}
	cout<<sum<<"jiiii";
	return sum;
}

int main()
{
	node * head=levelbuild();
	levelprint(head);
	cout<<endl;
	int n,k;
	cin>>n>>k;
	node *temp=compute(head,n);
	if(temp!=0)
		cout<<sumatK(temp,k);
	else
		cout<<"-1";
	return 0;
}