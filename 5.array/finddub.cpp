//this problem is to find dub in 1 - n+1 numbers where there will be numbers from 1 - n and dub always exists
//uses linked list cycle method works only if cycle exists

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;

	vector<int> v(n);

	for(int i=0;i<n;i++)
		cin>>v[i];

	int slow=v[0],fast=v[0];

	do
	{
		slow=v[slow];
		fast=v[v[fast]];
	}while(slow!=fast);

	slow=v[0];

	while(slow!=fast)
	{
		slow=v[slow];
		fast=v[fast];
	}


	cout<<fast;
	return 0;
}