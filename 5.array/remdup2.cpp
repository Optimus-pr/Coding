#include<bits/stdc++.h>
using namespace std;

int remdup(int *a,int n)
{
	int i=0;
	for(int j=1;j<n;j++)
	{
		if(a[i]!=a[j])	
		{
			i++;
			a[i]=a[j];
		}
	}
	return i+1;
}

int main()
{
	int n;
	cin>>n;

	int a[n];

	for(int i=0;i<n;i++)
		cin>>a[i];

	n=remdup(a,n);

	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";

	return 0;
}