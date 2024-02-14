//here we are given with an vec<string> we need to arrange those ele such that no formed should be maximum i.e 1,30,5,9,3=>953301
#include<bits/stdc++.h>
using namespace std;

bool cmp(string &a,string &b)//in cmp when returning true or false return the opposite of what is desired i.e if you want to return true then return false
{
    string first=a+b;
    string second=b+a;
    
    for(int i=0;i<first.size();i++)
    {
        if(first[i]<second[i])
            return false;
        if(first[i]>second[i])
            return true;
    }
    return false;
}

int main(){
    // code here
    vector<string> arr(n);
    int n;
    cin>>n;

    for(int i=0;i<n;i++)
        cin>>arr[i];

    string s="";
    sort(arr.begin(),arr.end(),cmp);
    for(int i=0;i<arr.size();i++)
        s+=arr[i];
    cout<<s;
    return 0;
}