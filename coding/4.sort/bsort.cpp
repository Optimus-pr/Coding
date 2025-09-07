#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;

	int a[n];

	for(int i=0;i<n;i++)
		cin>>a[i];

	for(int i=0;i<n-1;i++)
	{
		int flag=1;
		for(int j=0;j<n-1-i;j++)
		{
			if(a[j]>a[j+1])
			{
				flag=0;
				swap(a[j],a[j+1]);
			}
		}
		if(flag)
			break;
	}
	for(auto &val:a)
		cout<<val<<" ";
	return 0;
}