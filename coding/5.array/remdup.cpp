#include<bits/stdc++.h>
using namespace std;

int remdup(int *a,int n)
{
	set<int> s;
	for(int i=0;i<n;i++)
		s.insert(a[i]);
	int j=0;
	for(auto it:s)
	{
		a[j++]=it;
	}
	return j;
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