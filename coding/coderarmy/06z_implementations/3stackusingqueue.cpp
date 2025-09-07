#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Stack{
    queue<int> q1,q2;
    public:
    void push(int x)
    {
        if(q1.size()!=0)
            q1.push(x);
        else
            q2.push(x);
    }
    
    int pop(){
        int x;
        if(q1.size()==0 && q2.size()==0)
            return -1;
        if(q1.size())
        {
            while(q1.size()>1)
            {
                q2.push(q1.front());
                q1.pop();
            }
            x=q1.front();
            q1.pop();
        }
        else
        {
            while(q2.size()>1)
            {
                q1.push(q2.front());
                q2.pop();
            }
            x=q2.front();
            q2.pop();
        }
        return x;
    }
    
    int top(){
        if(q1.size()==0 && q2.size()==0)
            return -1;
        if(q1.size())
            return q1.back();//instead of using this we can simply do the same thing which we did for pop method but at the end don't pop the element just place it in the another queue
        if(q2.size())
            return q2.back();
        return 0;
        
    }
};

int main() {
    Stack s;
    s.push(1);
    s.push(2);
    cout<<s.pop();
    cout<<s.top();
    cout<<s.pop();
    cout<<s.pop();

    return 0;
}