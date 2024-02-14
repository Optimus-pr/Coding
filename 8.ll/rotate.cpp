#include<bits/stdc++.h>
using namespace std;

class node{
public:
	int data;
	node * next;

	node(int data){
		this->data=data;
		next=0;
	}
};

void insertrear(node * &head,int data)
{
	if(head==0)
	{
		head=new node(data);
		return;
	}
	node *t=head;
	while(t->next)
		t=t->next;
	node *nn=new node(data);
	t->next=nn;
}

void display(node * head)
{
	while(head)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
}

void rotate(node * &head,int k)
{
	int cnt=1;
	node * t=head;
	while(t->next)
	{
		cnt++;
		t=t->next;
	}
	k=k%cnt;
	t->next=head;

	int tmp=cnt-k;

	while(tmp)
	{
		t=t->next;
		tmp--;
	}
	head=t->next;
	t->next=0;
}

int main()
{
	node *head=0;
	insertrear(head,1);
	insertrear(head,2);
	insertrear(head,3);
	insertrear(head,4);
	insertrear(head,5);
	insertrear(head,6);
	insertrear(head,7);

	int k;
	cin>>k;

	rotate(head,k);
	display(head);
}