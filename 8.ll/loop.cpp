//first node of the loop

Node *s=head,*f=head;
    while(f && f->next)
    {
        s=s->next;
        f=f->next->next;
        if(s==f)
            break;
    }
    if(s==0 || f==0||f->next=0)//only 2 nodes then f->next ==0 helps or else seg fault
        return -1;
    s=head;
    while(s!=f)
    {
        s=s->next;
        f=f->next;
    }
    return s->data;











//removing loop in a linked list 

    Node* loop(Node* head) {
    Node* s = head, *f = head;

    while(f && f->next) {
        s = s->next;
        f = f->next->next;

        if(s == f) {
            return s; // Loop detected
        }
    }

    return nullptr; // No loop
}

void removeLoop(Node* head) {
    Node* h = loop(head);
    if(h == nullptr) {
        return; // No loop, no action needed
    }

    // Find the starting point of the loop
    Node* s = head;
    Node* f = h;

    // Special case: If the loop connects directly to the head
    if(f == head) {
        while(f->next != head) {
            f = f->next;
        }
        f->next = nullptr; // Break the loop
        return;
    }

    // General case: Move s and f until they meet at the start of the loop
    while(s->next != f->next) {
        s = s->next;
        f = f->next;
    }

    // Break the loop
    f->next = nullptr;
}
