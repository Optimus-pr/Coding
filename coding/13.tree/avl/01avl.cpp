// bst takes o(n) in worst case for all insertion deletion and searching and o(n2) for creation if runtime input or nlogn if array is given already


//but avl tree makes o(h) i.e o(logn) for all insert deletion and searching and o(nlogn) for creation 

//avl tree or more preferable red black tree will be used to implement set because every op can be done in logn time
// red black tree is prefered because it does less rotation comapred to avl tree even map used the same

//unordered set uses hashing which can boil down all these operations to o(1) 

//if we try to store some user defined type like class then it will throw an error because it doesn't know how to store them or sort them so we need to do operator overloading in that class which tell how the data be sorted

//set<int,greater<int> > s this stores the element in set in descending order
#include <iostream>
#include <queue>
using namespace std;

class Node
{
	public:
	int data,ht;
	Node *left,*right;

	Node(int value)
	{
		data=value;
		ht=1;
		left=right=0;
	}
};

void display(Node * root)
{
	queue<Node *> q;
	q.push(root);

	while(!q.empty())
	{
		Node * t=q.front();
		q.pop();

		if(t)
		{
			cout<<t->data<<" ";
			if(t->left)
				q.push(t->left);
			else
				q.push(NULL);

			if(t->right)
				q.push(t->right);
			else
				q.push(NULL);
		}
		else
		{
			cout<<"N ";
		}
	}
	cout<<endl;
}

// the aim of wrinting this fun eventhough we have ht as a memeber of the class is that sometimes root may be 0 so we need to and check to see if(root->left==0 )then return 0 if not then return ht everywhere in the code instead we will call this height fun which inturn does the task for us
int height(Node *root)
{
	if(root==0)
		return 0;

	return root->ht;
}

int isBalanced(Node *left,Node *right)
{
	return height(left)-height(right);
}

//try to image LL rotation by drawing the same once rotation is done the ht of child and root will be changed so recomputation is necessary
Node * leftRotation(Node * root)
{
	Node * child=root->right;
	Node * childLeft=child->left;

	child->left=root;
	root->right=childLeft;

	//here we need to make sure to update root->ht first before child as child will be parent so...
	root->ht=1+max(height(root->left),height(root->right));
	child->ht=1+max(height(child->left),height(child->right));

	return child;
}

Node * rightRotation(Node * root)
{
	Node * child=root->left;
	Node * childLeft=child->right;

	child->right=root;
	root->left=childLeft;

	root->ht=1+max(height(root->left),height(root->right));
	child->ht=1+max(height(child->left),height(child->right));
	

	return child;
}


//Note while writing rotation code always imagine by consider 3 nodes for LL LR RL RR rotations 
Node * insert(Node * root,int val)
{
	if(!root)
		return new Node(val);
	if(root->data<val)
		root->right=insert(root->right,val);
	else
		root->left=insert(root->left,val);

	root->ht=1+max(height(root->left),height(root->right));

	int balance=isBalanced(root->left,root->right);

	//left side imbalanace
	if(balance>1)
	{
		if(val<root->left->data)//LL imbalance so only right rotation across root is enought
		{
			return rightRotation(root);
		}
		else// LR imbalance so left rotation against root->left followed by right rotation against root is needed once left rotation is done we need to update root-Left to point to left rotated subtree
		{	
			root->left=leftRotation(root->left);
			return rightRotation(root);
		}
	}
	else if(balance<-1)//right side imbalance
	{
		if(val>root->right->data)
		{
			return leftRotation(root);
		}
		else
		{	
			root->right=rightRotation(root->right);
			return leftRotation(root);
		}
	}
	else
		return root;
}
// -6 -1 -8 -7 8 0 4
int main()
{
	Node * root=NULL;
	root=insert(root,-6);
	display(root);
	root=insert(root,-1);
	display(root);
	root=insert(root,-8);
	display(root);
	root=insert(root,-7);
	display(root);
	root=insert(root,8);
	display(root);
	root=insert(root,0);
	display(root);
	root=insert(root,4);
	display(root);

	display(root);
	return 0;
}