//here we will keep just a single variable that we will update when we push and pop new element i.e assume stack contains 5 so that is the only min ele so min=5 but when we try to push 3 we will not push 3 instead we push 2*3-1 and update min as 3...
//now while poping we check if s.top()<mn which acts as a flag i.e min is at the top of the stack so before poping update min=2*min-s.top() and then do s.pop()

#include<bits/stdc++.h>
using namespace std;

void popp(stack<int> &s,int &mn)
{
    if(s.top()<mn)
    {
        cout<<mn;
        mn=2*mn-s.top();
    }
    else
        cout<<s.top()<<" ";
}

int main()
{
    int n,mn;
    stack<int> s;
    cin>>n;

    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    mn=v[0];
    s.push(v[0]);

    for(int i=1;i<n;i++)
    {
        if(v[i]>mn)
            s.push(v[i]);
        else
        {
            s.push(2*v[i]-mn);
            mn=v[i];
        }
    }
    cout<<"top"<<s.top()<<endl;
    for(int i=0;i<n;i++)
    {
        popp(s,mn);
        s.pop();
        cout<<mn<<endl;
    }
    return 0;
}