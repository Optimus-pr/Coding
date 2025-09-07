// insertion o(n)
// delettion o(n)
// search o(n)
// creation
// 	a.array given 
// 		so sort it nlogn then create o(n)
// 	b.runtim
// 		o(n2)

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

node * create(node * head,int val)
{
	if(head==0)
		return new node(val);

	if(val<head->data)
		head->llink=create(head->llink,val);
	else
		head->rlink=create(head->rlink,val);

	return head;
}

void inorder(node *head)
{
	if(head==0)
		return;

	inorder(head->llink);
	cout<<head->data<<" ";
	inorder(head->rlink);
}

bool search(node *head,int val)
{
	if(head==0)
		return false;

	if(head->data==val)
		return true;
	else if(head->data<val)
		return search(head->rlink,val);
	else 
		return search(head->llink,val);
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

int main()
{
	int a[]={1,2,3,4,5,7,8};

	node *head=0;

	// for(auto &val:a)
	// 	head=create(head,val);
	// inorder(head);
	// cout<<endl;
	// cout<<search(head,0);
	
	head=sortedArrayToBST(a,0,6);
	inorder(head);

	return 0;

}