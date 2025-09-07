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
            s.push(2*v[i]-mn);//remeber example as 5 3 when 3 comes 1 will be pushed to stack updating min as 3 while poping 1 which is stack top will be small then min so recompute the min value from the variable and stack top
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


//or else we can follow another easy approach also i.e only used to give the min at the moment not to print the top 

//while pushing only we push the smallest till now by comparing with the top element 
stack<int> _push(int arr[], int n) {
    // your code here
    stack<int> s;
    if(n==0)
        return s;
    s.push(arr[0]);
    for(int i=1;i<n;i++)
    {
        if(arr[i]<s.top())
            s.push(arr[i]);
        else
            s.push(s.top());
    }
    
}

// Function to print minimum value in stack each time while popping.
void _getMinAtPop(stack<int> s) {
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    // your code here
}