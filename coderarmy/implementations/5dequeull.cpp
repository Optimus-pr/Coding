#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int d;
    node *next,*prev;
    
    node(int d)
    {
        this->d=d;
        next=0;prev=0;
    }
};

class dequeue{
    node *front,*rear;
    public:
    dequeue()
    {
        front=0;
        rear=0;
    }
    
    void push_back(int d)
    {
        if(front==0)
        {
            front=rear=new node(d);
        }
        else
        {
            node *t=new node(d);
            rear->next=t;
            t->prev=rear;
            rear=t;
        }
    }
    
    void push_front(int d)
    {
        if(front==0)
        {
            front=rear=new node(d);
        }
        else
        {
            node *t=new node(d);
            t->next=front;
            front->prev=t;
            front=t;
        }
    }
    
    int pop_back(){
        int x;
        if(front==0)
            return -1;
        else
        {
            node *t=rear;
            rear=rear->prev;
            if(rear)
                rear->next=0;
            else
                front=0;
            x=t->d;
            delete t;
        }
        return x;
    }
    
    int pop_front(){
        int x;
        if(front==0)
            return -1;
        else
        {
            node *t=front;
            front=front->next;
            if(front)
                front->prev=0;
            else
                rear=0;
            x=t->d;
            delete t;
        }
        return x;
    }
};

int main()
{
    dequeue d;
    d.push_back(1);
    d.push_front(2);
    d.push_back(3);
    cout<<d.pop_front();
    cout<<d.pop_front();
    cout<<d.pop_front();
    cout<<d.pop_back();
    d.push_back(1);
    d.push_front(2);
    d.push_back(3);
      cout<<d.pop_front();
    cout<<d.pop_back();
    return 0;
}