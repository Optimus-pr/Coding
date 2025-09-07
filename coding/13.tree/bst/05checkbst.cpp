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

bool check(node * head,int l,int r)
{
	if(head==NULL)
		return true;
	if(head->data<=l || head->data=>r)
		return false;
	return check(head->llink,l,head->data)&& check(head->rlink,head->data,r);
}

int mn=INT_MIN;
bool isBST(Node* root) {
    // Your code here
    if(root==0)
        return true;
    bool l= isBST(root->left);
    if(l==false)
        return false;
    if(root->data>mn)
    {
        mn=root->data;
    }
    else
        return false;
    return isBST(root->right);
}	

int main()
{
	node *head=levelbuild();
	inorder(head);
	cout<<check(head,-999,999);
 	
	
	return 0;

}