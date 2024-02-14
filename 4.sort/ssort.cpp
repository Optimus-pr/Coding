#include<bits/stdc++.h>
using namespace std;

void ssort(int *a,int n)
{
	for(int i=0;i<n-1;i++)
	{
		int mini=i;
		for(int j=i+1;j<n;j++)
		{
			if(a[j]<a[mini])
				mini=j;
		}
		swap(a[i],a[mini]);
	}
}

int main()
{
	int n;
	cin>>n;

	int a[n];

	for(int i=0;i<n;i++)
		cin>>a[i];

	ssort(a,n);

	for(auto &val:a)
		cout<<val<<" ";
	return 0;
}