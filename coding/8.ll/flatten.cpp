


Node * merge(Node *a,Node *b)
{
	if(!a)return b;
	if(!b)return a;

	Node * result;

	if(a->data<b->data)
	{
		result=a;
		result->bottom=merge(a->bottom,b);
	}
	else
	{
		result=b;
		result->bottom=merge(b->bottom,a);
	}
	return result;
}

Node* flatten(Node* head) 
{
	// Write your code here
	if(head->next==0)
		return head;

	Node * h=flatten(head->next);
	h=merge(head,h);
	return h;
}

   