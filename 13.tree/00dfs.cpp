#include<bits/stdc++.h>
using namespace std;

class node{
public:
	int data;
	node * llink,*rlink;

	node(int d)
	{
		data=d;
		llink=0;
		rlink=0;
	}
};


node * levelbuildtree(){
	int d;
	cin>>d;

	node * n=new node(d);

	queue<node *> q;
	q.push(n);

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
	return n;
}

void preorder(node * root)
{
	if(root==0)
		return;
	cout<<root->data<<" ";
	preorder(root->llink);
	preorder(root->rlink);
}

void iterpre(node * root)
{
	stack<node *> s;
	
	while(root || !s.empty())
	{
		if(root)
		{
			s.push(root);

			cout<<root->data<<" ";
			root=root->llink;	
		}
		else
		{
			root=s.top();
			s.pop();
			root=root->rlink;
		}
	};
}

void inorder(node * root)
{
	if(root==0)
		return;
	inorder(root->llink);
	cout<<root->data<<" ";
	inorder(root->rlink);
}

void iterin(node * root)
{
	stack<node *> s;

	while(root || !s.empty())
	{
		if(root)
		{
			s.push(root);
			root=root->llink;
		}
		else{
			root=s.top();
			s.pop();
			cout<<root->data<<" ";
			root=root->rlink;
		}
	}
}

void postorder(node * root)
{
	if(root==0)
		return;
	postorder(root->llink);
	postorder(root->rlink);
	cout<<root->data<<" ";
}

vector<int> iterpost(node *root)
{
	node * cur=root,*temp;
	stack<node *> s;
	vector<int> p;

	while(cur!=NULL || !s.empty())
	{
		if(cur)
		{
			s.push(cur);
			cur=cur->llink;
		}
		else
		{
			temp=s.top()->rlink;
			if(temp==NULL)
			{
				temp=s.top();
				s.pop();
				p.push_back(temp->data);
				while(!s.empty() && temp==s.top()->rlink)
				{
					temp=s.top();
					s.pop();
					p.push_back(temp->data);
				}
			}
			else
				cur=temp;
		}
	}
	return p;
}

bool isleaf(node *root)
{
	if(root->llink==0 && root->rlink==0)
		return true;
	return false;
}

void modifiedlevel(node * root,string &s)
{
	
       queue<node *> q;
       q.push(root);
       
       while(!q.empty())
       {
           node *t=q.front();
           q.pop();
          	
           cout<<t->data<<endl;
           s.push_back(t->data);
           
           if(t->llink)
            q.push(t->llink);
           else if(!isleaf(t))
            s.push_back('$');
            
           if(t->rlink)
            q.push(t->rlink);
           else if(!isleaf(t))
            s.push_back('$');
          
       }
       cout<<s<<endl;
    
}

int main()
{
	string s="";
	node * root=levelbuildtree();
	modifiedlevel(root,s);
	//inorder(root);

	cout<<s<<endl;

	return 0;
}