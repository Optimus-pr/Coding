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


void inorder(node *head)
{
	if(head==0)
		return;

	inorder(head->llink);
	cout<<head->data<<" ";
	inorder(head->rlink);
}


node * sortedArrayToBST(int *a,int s,int e)
{
	if(s>e)
		return NULL;

	int mid=(s+e)/2;
	node *root=new node(a[mid]);
	root->llink=sortedArrayToBST(a,s,mid-1);
	root->rlink=sortedArrayToBST(a,mid+1,e);

	return root;
}

int seal(node * head,int key)
{
	int ans=-999;

	while(head)
	{
		if(head->data==key)
			return key;
		else if(head->data<key)
			head=head->rlink;
		else
		{
			ans=head->data;
			head=head->llink;
		}
	}
	return ans;
}

int flor(node * head,int key)
{
	int ans=999;

	while(head)
	{
		if(head->data==key)
			return key;
		else if(head->data>key)
			head=head->llink;
		else
		{
			ans=head->data;
			head=head->rlink;
		}
	}
	return ans;
}

int main()
{
	int a[]={1,3,5,7,9,11,15};

	node *head=0;

	head=sortedArrayToBST(a,0,6);
	// inorder(head);
	int ans=flor(head,16);
	if(ans==-999)
		cout<<"Ceil doesn't exists";
	else
		cout<<ans;
	return 0;

}