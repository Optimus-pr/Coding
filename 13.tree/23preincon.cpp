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

node * buildtree(vector<int> in,int is,int ie,vector<int> pre,int ps,int pe,unordered_map<int,int> &m)
{
	if(ps>pe || is>ie)
		return NULL;

	node *head=new node(pre[ps]); 

	int inRoot=m[head->data];
	int numsLeft=inRoot-is;
	head->llink=buildtree(in,is,inRoot-1,pre,ps+1,ps+numsLeft,m);//ps,ps+numsleft-1
	head->rlink=buildtree(in,inRoot+1,ie,pre,ps+numsLeft+1,pe,m);//ps+numsleft,pe-1

	return head;
}

node * construct(vector<int> in,vector<int> pre)
{
	int n=in.size();
	unordered_map<int,int> m;
	for(int i=0;i<n;i++)
	{
		m[in[i]]=i;
	}
	node * root=buildtree(in,0,n-1,pre,0,n-1,m);
	return root;
}


int main()
{
	node *head=0;
	int n,ele;
	cin>>n;
	vector<int> in(n),pre(n);
	cout<<"Enter preorder \n";
	for(int i=0;i<n;i++)
		cin>>pre[i];

	cout<<"Enter inorder \n";
	for(int i=0;i<n;i++)
		cin>>in[i];

	node * root=construct(in,pre);

	display(root);
	
	return 0;
}