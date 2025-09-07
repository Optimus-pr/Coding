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