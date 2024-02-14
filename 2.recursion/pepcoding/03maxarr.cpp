#include<bits/stdc++.h>
using namespace std;

int fun(int *a,int i,int n)
{
	if(i==n-1)
		return a[i];
	return max(a[i],fun(a,i+1,n));
}

int main()
{
	int n;
	cin>>n;

	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	cout<<fun(a,0,n);
	return 0;
}