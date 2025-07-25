// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Queue{
    stack<int> s1,s2;
    public:
    void push(int x)
    {
        s1.push(x);
    }
    
    int pop(){
        int x;
        if(s2.size()==0 && s1.size()==0)
            return -1;
        if(s2.size())
        {
            x=s2.top();
            s2.pop();
        }
        else
        {
            while(s1.size())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return x;
    }
    
    int front(){
    if(s1.size()==0 && s2.size()==0)
        return -1;
    if(s2.size()==0)
    {
        while(s1.size())
        {
            s2.push(s1.top());
            s1.pop();
        }
    }
    return s2.top();
}
};



int main() {
    // Write C++ code here
    Queue q;
    q.push(1);
    q.push(2);
    cout<<q.front();
    cout<<q.pop();
    cout<<q.pop();
    cout<<q.pop();

    return 0;
}