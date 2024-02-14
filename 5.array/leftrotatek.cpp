#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;

	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];

	k=(k%n);
	reverse(a,a+k);
	reverse(a+k,a+n);
	reverse(a,a+n);

	for(auto &val:a)
		cout<<val<<" ";
	return 0;
}