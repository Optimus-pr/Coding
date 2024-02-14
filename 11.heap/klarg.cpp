#include<bits/stdc++.h>
using namespace std;

void klargest(int *a,int n,int k)
{
	priority_queue<int,vector<int>,greater<int> > minh;

	for(int i=0;i<n;i++)
	{
		minh.push(a[i]);

		if(minh.size()>k)
			minh.pop();
	}

	while(minh.size())
	{
		cout<<minh.top()<<" ";
		minh.pop();
	}
}

int main()
{
	int n,k;
	cin>>n;

	int a[n];

	for(int i=0;i<n;i++)
		cin>>a[i];
	cin>>k;

	klargest(a,n,k);
}