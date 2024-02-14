//this is only for 1 sale 

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;

	int a[n];

	for(int i=0;i<n;i++)
		cin>>a[i];

	int min=999,pro=0;

	for(int i=0;i<n;i++)
	{
		if(a[i]<min)
			min=a[i];
		else
			pro=max(pro,a[i]-min);
	}
	cout<<pro;//if pro is 0 then there is no chance of profit
	 
}

for(int i=1;i<n;i++)
{
	if(a[i]>a[i-1])
		profit+=a[i]-a[i-1];
}