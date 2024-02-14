#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
int h[N];
int dp[N];

int frog(int n,int k)
{
	int cost=N;

	if(n==0)return 0;

	for(int i=1;i<=k;i++)
	{
		if(n-i>=0)
		cost=min(cost,frog(n-i,k)+abs(h[n]-h[n-i]));
	}
	return cost;
}

int main()
{
	memset(dp,-1,sizeof(dp));
	int n,k;
	cin>>n>>k;

	for(int i=0;i<n;i++)
		cin>>h[i];

	cout<<frog(n-1,k);
	return 0;
}