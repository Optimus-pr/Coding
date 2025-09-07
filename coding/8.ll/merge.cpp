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

void display(node * head)
{
	while(head)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;
}

// node * merge(node * &h1,node * &h2)
// {
// 	node *h3,*temp;

// 	if(h1->data<h2->data)
// 	{
// 		h3=h1;temp=h1;h1=h1->next;
// 	}
// 	else
// 	{
// 		h3=h2;temp=h2;h2=h2->next;
// 	}

// 	while(h1 && h2)
// 	{
// 		if(h1->data<h2->data)
// 		{
// 			temp->next=h1;
// 			temp=h1;
// 			h1=h1->next;
// 		}
// 		else
// 		{
// 			temp->next=h2;
// 			temp=h2;
// 			h2=h2->next;
// 		}
// 	}

// 	if(h1==0)
// 		temp->next=h2;
// 	if(h2==0)
// 		temp->next=h1;

// 	return h3;
// }

node* merge(node* &a, node* &b) {
    if (!a) return b;
    if (!b) return a;

    node* result;
    if (a->data < b->data) {
        result = a;
        result->next = merge(a->next, b);
    } else {
        result = b;
        result->next = merge(a, b->next);
    }

    return result;
}

int main()
{
	node * head1=0;
	insertrear(head1,1);
	insertrear(head1,3);
	insertrear(head1,5);
	insertrear(head1,7);
	insertrear(head1,8);
	node * head2=0;
	insertrear(head2,1);
	insertrear(head2,2);
	insertrear(head2,4);
	insertrear(head2,6);

	display(head1);
	display(head2);

	node *head3=merge(head1,head2);
	display(head3);

}