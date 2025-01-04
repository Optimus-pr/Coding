#include<bits/stdc++.h>
using namespace std;

void merg(vector<int> &v,int s,int mid,int e)
{
    int i=s,j=mid+1,k=s;
    vector<int> b(v.size());
    while(i<=mid && j<=e)
    {
        if(v[i]<=v[j])
        {
            b[k++]=v[i++];
        }
        else
            b[k++]=v[j++];

    }

    for(;i<=mid;i++)
        b[k++]=v[i];
    for(;j<=e;j++)
        b[k++]=v[j];

    for(i=s;i<=e;i++)
        v[i]=b[i];
}

void msort(vector<int> &v,int s,int e)
{
    if(s<e)
    {
        int mid=(s+e)/2;
        msort(v,s,mid);
        msort(v,mid+1,e);
        merg(v,s,mid,e);
    }
}
int main()
{
    vector<int> v={2,1,4,5,6};
    msort(v,0,4);

    for(auto &val:v)
        cout<<val<<" ";
    return 0;
}