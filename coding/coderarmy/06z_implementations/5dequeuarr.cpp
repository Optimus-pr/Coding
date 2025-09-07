#include<bits/stdc++.h>
using namespace std;

class dequeue{
    int front,rear,n;
    int * v;
    public:
    dequeue(int s)
    {
        v=new int[s];
        front=rear=-1;
        n=s;
    }
    
    bool isEmpty(){
        if(front==-1)
            return true;
        return false;
    }
    
    bool isFull(){
        if((rear+1)%n==front)
            return true;
        return false;
    }
    
    void push_back(int d)
    {
        if(isFull())
            return;
        if(isEmpty())
        {
            front=rear=0;
            v[rear]=d;
        }
        else
        {
            rear=(rear+1)%n;
            v[rear]=d;
        }
    }
    
    void push_front(int d)
    {
        if(isFull())
            return;
        if(isEmpty())
        {
            front=rear=0;
            v[rear]=d;
        }
        else
        {
            front=(front-1+n)%n;
            v[front]=d;
        }
    }
    
    int pop_front(){
        int x;
        if(isEmpty())
            return -1;
        if(front==rear){
            x=v[front];
            front=-1;
            rear=-1;
        }
        else{
            x=v[front];
            front=(front+1)%n;
        }
        return x;
    }
    
    int pop_back(){
        int x;
        if(isEmpty())
            return -1;
        if(front==rear){
            x=v[rear];
            front=-1;
            rear=-1;
        }
        else{
            x=v[rear];
            rear=(rear-1+n)%n;
        }
        return x;
    }
};

int main()
{
    dequeue d(5);
    d.push_back(1);
    d.push_back(2);
    d.push_back(3);
    d.push_front(4);
    d.push_front(5);
    cout<<d.pop_front();
    cout<<d.pop_back();
    cout<<d.pop_front();
    cout<<d.pop_front();
    cout<<d.pop_back();
    cout<<d.pop_front();
    return 0;
}