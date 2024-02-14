//this code returns the middle node if there exists 2 nodes then it will return the 2nd one

#include<bits/stdc++.h>
using namespace std;

class node
{
public:
	int data;
	node * next;

	node(int data){
		this->data=data;
		next=0;
	}
};

void insertrear(node* &h,int data)
{
	if(h==0)
	{
		h=new node(data);
		h->next=0;
		return;
	}
	node * t=h;
	while(t->next)
		t=t->next;
	node * nn=new node(data);
	t->next=nn;

}

void middle(node * head)
{
	node *s=head,*f=head;

	while(f && f->next)
	{
		s=s->next;
		f=f->next->next;
	}
	cout<<s->data;

}

int main()
{
	node * head=NULL;
	insertrear(head,1);
	insertrear(head,2);
	insertrear(head,3);
	insertrear(head,4);
	insertrear(head,5);
	insertrear(head,6);
	insertrear(head,7);
	insertrear(head,8);
	middle(head);
}