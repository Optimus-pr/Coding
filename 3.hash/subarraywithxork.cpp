//finding the cnt of subarray with xor of k

#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;

	int a[n];
	unordered_map<int,int> u;

	for(int i=0;i<n;i++)
		cin>>a[i];

	int xr=0,cnt=0;

	for(int i=0;i<n;i++)
	{
		xr^=a[i];
		if(xr==k)
			cnt++;
		int y=xr^k;
		if(u.find(y)!=u.end())
			cnt+=u[y];
		
		u[xr]++;
	}
	cout<<cnt;

}