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

int closest(node * head,int key)
{
	int min=1000,closest;
	while(head)
	{
		int diff=abs(head->data-key);

		if(diff==0)
			return head->data;
		else if(diff<min)
		{
			min=diff;
			closest=head->data;
		}

		if(head->data<key)
			head=head->rlink;
		else 
			head=head->llink;
	}
	return closest;
}

int main()
{
	int a[]={1,2,3,4,5,6,7,8};
	node * head=buildtree(a,0,7);
	// inorder(head);
	cout<<closest(head,9);
	return 0;
}