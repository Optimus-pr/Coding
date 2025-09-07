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

node * rtmostinlt(node * head)
{
	while(head->rlink)
		head=head->rlink;
	return head;
}

node * checker(node * head)
{
	if(head->llink==0)
		return head->rlink;
	else if (head->rlink==0)
		return head->llink;
	node * right=head->rlink;
	node * lr=rtmostinlt(head->llink);
	lr->rlink=right;
	return head->llink;
}

node *del(node * head,int key)
{
	if(head->data==key)
	{
		node * root=checker(head);
		return root;
	}

	node * dummy=head;

	while(head)
	{
		if(head->data >key)
		{
			if(head->llink && head->llink->data==key)
			{
				head->llink=checker(head->llink);
				break;
			}
			else
				head=head->llink;
		}
		else
		{
			if(head->rlink && head->rlink->data==key)
			{
				head->rlink=checker(head->rlink);
				break;
			}
			else
				head=head->rlink;
		}
	}
	return dummy;
}


int main()
{
	node *head=levelbuild();
	inorder(head);
	cout<<endl;
 	head=del(head,9);
	inorder(head);
	
	return 0;

}