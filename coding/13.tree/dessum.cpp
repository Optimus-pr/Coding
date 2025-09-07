#include<bits/stdc++.h>
using namespace std;

class node{
public:
	int data;
	node *llink,*rlink;

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

	queue<node *> q;

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

void display(node * &head)
{
	if(head==0)
		return;

	queue<node *>q;

	q.push(head);
	q.push(NULL);

	while(!q.empty())
	{
		node *d=q.front();
		q.pop();

		if(d==0)
		{
			cout<<endl;
			if(!q.empty())
				q.push(NULL);
		}
		else
		{
			cout<<d->data<<" ";
			if(d->llink)
				q.push(d->llink);
			if(d->rlink)
				q.push(d->rlink);
		}
	}
}


// o/p:-1 2 3 will result in 6 2 3
int descendant(node *&head)
{
	if(head==0)
		return 0;
	int lt=descendant(head->llink);
	int rt=descendant(head->rlink);
	return head->data=lt+rt+head->data;
}


//o/p:-1 2 3 will result in 5 2 3
int descendant1(node *&head)
{
	if(head==0)
		return 0;

	int temp=head->data;

	int lt=descendant1(head->llink);
	int rt=descendant1(head->rlink);

	if(lt==0 && rt==0)
		return head->data;
	head->data=lt+rt;
	return head->data+temp;
}



int main()
{
	node *head=0;

	levelbuild(head);
	display(head);
	descendant1(head);
	display(head);

	return 0;
}