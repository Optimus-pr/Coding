#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,key;
	cin>>n;

	int a[n];

	for(int i=0;i<n;i++)
		cin>>a[i];
	cin>>key;

	int ind=upper_bound(a,a+n,key)-a;

	

	if(ind<n)cout<<a[ind];
	else
		cout<<"-1";
}