#include<bits/stdc++.h>
using namespace std;

class node{
public:
	int data;
	node *llink,*rlink;

	node(int data)
	{
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

void inorder(node * head)
{
	if(head==0)
		return;
	inorder(head->llink);
	cout<<head->data<<" ";
	inorder(head->rlink);
}

int lca(node *head,int a,int b)
{
	while(head)
	{
		if(a<head->data && b<head->data)
			head=head->llink;
		else if(a>head->data && b>head->data)
			head=head->rlink;
		else
			return head->data;
	}
	
}

node * build(int *a,int l,int h)
{
	if(l>h)
		return NULL;

	int mid=(l+h)/2;

	node * head=new node(a[mid]);
	head->llink=build(a,l,mid-1);
	head->rlink=build(a,mid+1,h);

	return head;
}

int main()
{
	int ar[]={1,2,3,4,5,6,7,8};
	node *head=build(ar,0,7);
	inorder(head);
	int a,b;
	cin>>a>>b;

	cout<<lca(head,a,b);
	
	return 0;
}