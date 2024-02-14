#include<bits/stdc++.h>
using namespace std;

class node
{
public:
	int data;
	node* left;
	node *right;

	node (int d)
	{
		data=d;
		left=0;
		right=0;
	}
};



node * levelbuild()
{
	int d;
	cin>>d;
	node *head=new node(d);

	queue<node *> q;
	q.push(head);

	while(!q.empty())
	{
		node * t=q.front();
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
			if(t->left)
				q.push(t->left);
			if(t->right)
				q.push(t->right);
		}
	}
}

int printmax(node * head)
{
	
	if(head->left==0 && head->right==0)
	{
		return head->data;
	}

	int l=printmax(head->left);
	int r=printmax(head->right);

	return max(l,r)+head->data;

}

int main()
{
	node *head=levelbuild();
	levelprint(head);

	cout<<printmax(head);
	return 0;
}