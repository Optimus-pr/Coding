#include<bits/stdc++.h>
using namespace std;

class node
{
public:
	int data;
	node * next;

	node(int data)
	{
		this->data=data;
		next=NULL;
	}
};

void insertfront(node* &head,int data)
{
	if(head==0)
	{
		head=new node(data);
		return;
	}
	node * nn=new node(data);
	nn->next=head;
	head=nn;
}

void insertrear(node * &head,int data)
{
	if(head==0)
	{
		head=new node(data);
		return;
	}
	node * t=head;
	while(t->next!=0)
		t=t->next;
	node * nn=new node(data);
	t->next=nn;
}

void deletefront(node * &head)
{
	if(head==0)
		return;
	node * t=head->next;
	delete head;
	head=t;
}

void deleterear(node * &head)
{
	if(head==0)
		return;
	node * cur=head;
	node * prev=NULL;

	while(cur->next!=NULL)
	{
		prev=cur;
		cur=cur->next;
	}	

	prev->next=cur->next;
	delete cur;

}

void display(node * head)
{
	while(head)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
}

void insertbypos(node * &head,int pos,int data)
{
	if(head==0 && pos==1)
	{
		head=new node(data);
		return;
	}
	else if(head==0 && pos!=1)
	{
		cout<<"Invalid position1\n";
		return;
	}
	else if(pos==1)
	{
		node *nn=new node(data);
		nn->next=head;
		head=nn;
		return;
	}

	int i=1;
	node * t=head;
	while(t && i!=pos-1)
	{
		t=t->next;
		i++;
	}
	if(t)
	{	
		node * nn=new node(data);
		nn->next=t->next;
		t->next=nn;
	}
	else
	{
		cout<<"Invalid postion\n";
		return;
	}
}

void deletebypos(node * &head,int pos)
{
	if(head==NULL)
		return;
	int i=1;
	if(pos==1)
	{
		node * t=head->next;
		delete head;
		head=t;
		return;
	}

	node * t=head;
	while(t && i!=pos-1)
	{
		i++;
		t=t->next;
	}
	if(t==0 || t->next==0)
	{
		cout<<"invalid position\n";
		return;
	}
	else
	{
		node * temp=t->next;
		t->next=temp->next;
		delete temp;
		return;
	}
}

void insertbyorder(node * &head,int data)
{
	if(head==0)
	{
		head=new node(data);
		return;
	}
	if(data<head->data)
	{
		node * nn=new node(data);
		nn->next=head;
		head=nn;
		return;
	}
	node *prev=0,*cur=head;
	while(cur && cur->data<data)
	{
		prev=cur;
		cur=cur->next;
	}
	node *nn=new node(data);
	nn->next=cur;
	prev->next=nn;
}

void sort(node * head)
{
	node * t=head;
	int cnt=0;
	while(t)
	{
		cnt++;
		t=t->next;
	}

	for(int i=0;i<cnt-1;i++)
	{
		t=head;
		for(int j=0;j<cnt-1-i;j++)
		{
			if(t->data >t->next->data)
			{
				int temp=t->data;
				t->data=t->next->data;
				t->next->data=temp;
			}
				t=t->next;
		}
	}
}

void itereverse(node *&head)
{
	node *q=head,*r=0,*p;
	while(q)
	{
		p=q->next;
		q->next=r;
		r=q;
		q=p;
	}
	head=r;
}

node * recreverse(node * head)
{
	if(head==0 || head->next==0)
		return head;
	node *shead=recreverse(head->next);
	head->next->next=head;
	head->next=NULL;
	return shead;
}

int main()
{
	node * head=NULL;
	insertfront(head,10);
	insertfront(head,20);
	insertfront(head,30);
	insertbypos(head,1,40);
	insertbypos(head,2,15);
	insertbypos(head,6,22);
	// insertbypos(head,8,8);
	// deletebypos(head,1);
	// deletebypos(head,2);
	// deletebypos(head,6);
	sort(head);
	insertbyorder(head,0);
	insertbyorder(head,100);
	insertbyorder(head,25);
	// itereverse(head);
	head=recreverse(head);

	display(head);

	return 0;
}