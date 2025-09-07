#include<bits/stdc++.h>
using namespace std;

void rec(int *a,vector<int> v,int n,int ind)
{

	if(ind==n)
	{
		for(auto it:v)
			cout<<it<<" ";
		cout<<endl;
		return;
	}

	for(int i=ind;i<n;i++)
	{
		swap(v[i],v[ind]);
		rec(a,v,n,ind+1);
		swap(v[i],v[ind]);
	}
}

int main()
{
	int n;
	cin>>n;

	int a[n];
	vector<int> v;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		v.push_back(a[i]);
	}

	rec(a,v,n,0);
}