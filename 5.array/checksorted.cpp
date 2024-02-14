#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,flag;
	cin>>n;

	int a[n];

	for(int i=0;i<n;i++)
		cin>>a[i];

	for(int i=0;i<n-1;i++)
	{
		flag=0;
		if(a[i]>a[i+1])
		{
			flag=1;
			break;
		}
	}
	
	if(flag)
		cout<<"False";
	else
		cout<<"True";
	return 0;
}