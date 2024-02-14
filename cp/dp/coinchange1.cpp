#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
int dp[N];
int coins(int amt,vector<int> & v)
{
	if(dp[amt]!=-1)return dp[amt];
	if(amt==0)return 0;
	int ans=N;
	for(auto coin: v)
	{
		if(amt-coin>=0)
		ans=min(ans,coins(amt-coin,v)+1);
	}
	return dp[amt]=ans;
}

int main()
{
	memset(dp,-1,sizeof(dp));
	int n,amt;
	cin>>n>>amt;
	vector<int> v(n);
	for(int i=0;i<n;i++)
		cin>>v[i];
	int ans=coins(amt,v);
	ans>=N?cout<<"-1":cout<<ans;
	return 0;
}