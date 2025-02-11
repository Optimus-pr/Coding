#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node *left;
	Node *right;

	Node(int d)
	{
		data=d;
		left=0;
		right=0;
	}
};

void levelorder(Node *&head)
{
	queue<Node *> q;
	int d;
	cin>>d;
	head=new Node(d);
	q.push(head);

	while(!q.empty())
	{
		Node *t=q.front();
		q.pop();

		cin>>d;
		if(d!=-1){
			t->left=new Node(d);
			q.push(t->left);
		}

		cin>>d;
		if(d!=-1){
			t->right=new Node(d);
			q.push(t->right);
		}
	}
}

void display(Node * head)
{
	queue<Node *> q;
	q.push(head);
	q.push(NULL);

	while(!q.empty())
	{
		Node *t=q.front();
		q.pop();

		if(t)
		{
			cout<<t->data<<" ";
			if(t->left)
				q.push(t->left);
			if(t->right)
				q.push(t->right);
		}
		else
		{
			cout<<endl;
			if(!q.empty())
				q.push(NULL);
		}

	}
	cout<<endl;
}

int checkChild(Node *head,bool &flag)
{
	if(head->left==0 && head->right==0)
		return head->data;
	int l=checkChild(head->left,flag);
	int r=checkChild(head->right,flag);

	if(l+r!=head->data)
		flag=false;

	return head->data;
}

void makeChild(Node *head)
{
	if(head==0)
		return;

	int t=0;
	if(head->left)
		t+=head->left->data;
	if(head->right)
		t+=head->right->data;

	if(head->data<=t)
		head->data=t;
	else
	{
		if(head->left)
			head->left->data=t;
		if(head->right)
			head->right->data=t;
	}
	makeChild(head->left);
	makeChild(head->right);
	t=0;
	if(head->left)t+=head->left->data;
	if(head->right)t+=head->right->data;
	if(head->left || head->right)head->data=t;

}

int main()
{
	Node *head;
	bool flag=true;
	levelorder(head);
	display(head);
	checkChild(head,flag);

	if(flag)
		cout<<"yess";
	else
	{
		makeChild(head);
		display(head);
	}
	return 0;
}