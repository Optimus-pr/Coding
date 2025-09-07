#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;

	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];

	k=k%n;//this is helpful when there is only 1 ele in the array and the k value is great than 1 it will cause segmentation fault also when k will be greater than n v.end()-k will results fault
	reverse(a,a+n-k);
	reverse(a+n-k,a+n);
	reverse(a,a+n);

	for(auto &val:a)
		cout<<val<<" ";
	return 0;

}