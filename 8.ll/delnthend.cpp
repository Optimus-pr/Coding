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

void delnod(node * &head,int pos)
{
	node * t=new node(0);
	t->next=head;
	node *s=t,*f=t;

	int i=0;
	while(i!=pos)
	{
		f=f->next;i++;
	}
	if(f)
	{
		while(f->next)
		{
			s=s->next;
			f=f->next;
		}

		if(s==t)
		{
			node *d=t->next;
			head=head->next;
			t->next=head->next;
			delete d;
		}
		else
		{
			node *tmp=s->next;
			s->next=tmp->next;
			delete tmp;
		}
	}
	else
		cout<<"invalid position\n";
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
	//display(head);

	//delnod(head,8);
	//display(head);
}