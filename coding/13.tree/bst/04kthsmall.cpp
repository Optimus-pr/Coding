//here in kthsmall function receiving value of cnt must be by referecen as each rec call will refer to the updated value of cnt or else if it is pass by value each call will contain it's own version of cnt.

#include<bits/stdc++.h>
using namespace std;

class node{
public:
	int data;
	node *llink;
	node *rlink;

	node(int d){
		data=d;
		llink=rlink=0;
	}
};

node * con(int * a,int s,int e)
{
	if(s>e)
		return 0;

	int mid=(s+e)/2;
	node *head=new node(a[mid]);
	head->llink=con(a,s,mid-1);
	head->rlink=con(a,mid+1,e);

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

int kthsmall(node * head,int &cnt)
{
	if(head==0)
		return -1;
	
	
	int l=kthsmall(head->llink,cnt);
	if(l!=-1)
		return l;
	cnt--;
	cout<<head->data<<" "<<cnt<<endl;
	if(cnt==0)
		return head->data;
	
	return kthsmall(head->rlink,cnt);
}

//just changing the traversal order from left to right  -> right to left will give us kthlargest 
int kthlarg(node * head,int &cnt)
{
	if(head==0)
		return -1;
	
	
	int r=kthlarg(head->rlink,cnt);
	if(r!=-1)
		return r;
	cnt--;
	cout<<head->data<<" "<<cnt<<endl;
	if(cnt==0)
		return head->data;
	
	return kthlarg(head->llink,cnt);
}

//we can use this approach also i.e call this fun which will have the value updated in the variable so return that variable
void fun(Node * root,int &sum,int &k)
{
    if(root==0)
        return;
    fun(root->right,sum,k);
    if(--k==0){
        sum=root->data;
        return;
   	}	
    else if(k<0)
        return;
    fun(root->left,sum,k);
}

int main()
{
	int a[]={1,2,3,4,5,6};
	node * root=con(a,0,5);
	int cnt=4;
	cout<<kthlarg(root,cnt);
	return 0;
}