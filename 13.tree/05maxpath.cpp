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

int maxpath(node *&head,int &maxi)
{
	if(head==0)
		return 0;

	int lt=max(0,maxpath(head->llink,maxi));//0,maxpath bcause we are trying to neglect the negative wts
	int rt=max(0,maxpath(head->rlink,maxi));
	maxi=max(maxi,lt+rt+head->data);

	return max(lt,rt)+head->data;
}

int main()
{
	node *head=0;
	int maxi=-999;

	levelbuild(head);
	display(head);

	maxpath(head,maxi);
	
	return 0;
}