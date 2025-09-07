#include<bits/stdc++.h>
using namespace std;

class node{
public:
	int data;
	node *llink;
	node *rlink;

	node(int data){
		this->data=data;
		llink=0;
		rlink=0;
	}
};

void levelbuild(node * &head)
{
	int d;
	cin>>d;

	queue<node*> q;

	if(d!=-1)
	{
		head=new node(d);
		q.push(head);
	}

	while(!q.empty())
	{
		node *t=q.front();
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
}

void display(node * head)
{
	if(head==0)
		return;

	queue<node * >q;
	q.push(head);
	q.push(NULL);

	while(!q.empty())
	{
		node *t=q.front();
		q.pop();
		if(t==NULL)
		{
			cout<<endl;
			if(!q.empty())
				q.push(NULL);
		}
		else
		{
			cout<<t->data<<" ";
			if(t->llink)
				q.push(t->llink);
			if(t->rlink)
				q.push(t->rlink);
		}
	}
}

void morrisin(node *head)
{
	vector<int> in;
	while(head)
	{
		if(head->llink==0)
		{
			in.push_back(head->data);
			head=head->rlink;
		}
		else
		{
			node *temp=head->llink;
			while(temp->rlink && temp->rlink!=head)
				temp=temp->rlink;
			if(temp->rlink==0)
			{
				temp->rlink=head;
				head=head->llink;
			}
			else
			{
				temp->rlink=0;
				in.push_back(head->data);
				head=head->rlink;
			}
		}
	}
	for(auto &val:in)
		cout<<val<<" ";
	cout<<endl;
}

void morrispre(node *head)
{
	vector<int> pre;
	while(head)
	{
		if(head->llink==0)
		{
			pre.push_back(head->data);
			head=head->rlink;
		}
		else
		{
			node *temp=head->llink;
			while(temp->rlink && temp->rlink!=head)
				temp=temp->rlink;
			if(temp->rlink==0)
			{
				temp->rlink=head;
				pre.push_back(head->data);
				head=head->llink;
			}
			else
			{
				temp->rlink=0;
				
				head=head->rlink;
			}
		}
	}
	for(auto &val:pre)
		cout<<val<<" ";
	cout<<endl;
}

vector<int> morrispostOrder(Node* node) {
        // code here
        vector<int> ans;
        
        while(node)
        {
            if(node->right==0)
            {
                ans.push_back(node->data);
                node=node->left;
            }
            else
            {
                Node * t=node->right;
                while(t->left && t->left!=node)
                    t=t->left;
                if(t->left==0)
                {
                    t->left=node;
                    ans.push_back(node->data);
                    node=node->right;
                }
                else
                {
                    node=node->left;
                    t->left=0;
                }
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }


int main()
{
	node *head=0;

	levelbuild(head);
	display(head);
		
	morrispre(head);
	
	return 0;
}


