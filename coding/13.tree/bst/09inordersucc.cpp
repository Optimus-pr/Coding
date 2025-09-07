#include<bits/stdc++.h>
using namespace std;

class node
{
public:
	int data;
	node *llink;
	node *rlink;

	node(int data)
	{
		this->data=data;
		llink=0;
		rlink=0;
	}
};

node * buildtree(int *a,int s,int e)
{
	if(s>e)
		return NULL;

	int mid=(s+e)/2;
	node * head=new node(a[mid]);
	head->llink=buildtree(a,s,mid-1);
	head->rlink=buildtree(a,mid+1,e);

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

node * inordersucc(node * head,node * t)
{
	node * temp=t->rlink;
	node * ans=NULL;

	if(temp)
	{
		while(temp->llink)
			temp=temp->llink;
		return temp;
	}
	else
	{
		while(head)
		{
			if(head->data<t->data)
				head=head->rlink;
			else if(head->data>t->data)
			{
				ans=head;
				head=head->llink;
			}
			else 
				break;
		}
		return ans;
	}

}

node * search(node * head,int key)
{
	while(head)
	{
		if(head->data<key)
			head=head->rlink;
		else if (head->data> key)
			head=head->llink;
		else
			return head;
	}
	return NULL;
}

int main()
{
	int a[]={1,2,3,4,5,6,7,8};
	node * head=buildtree(a,0,7);
	// inorder(head);
	node * t=search(head,8);
	node * ans=inordersucc(head,t);
	
	if(ans)
		cout<<ans->data<<" ";
	else
		cout<<"NULL";
	return 0;
}

