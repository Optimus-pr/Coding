#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
int dp[N];
int ht[N];

int frog(int n)
{
	int cost=N;
	if(dp[n]!=-1)return dp[n];
	
	if(n==0)return 0;

	cost=min(cost,frog(n-1)+abs(ht[n]-ht[n-1]));

	if(n>1)
	cost=min(cost,frog(n-2)+abs(ht[n]-ht[n-2]));
	
	return dp[n]=cost;
}
int main()
{
	memset(dp,-1,sizeof(dp));
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>ht[i];
	cout<<frog(n-1);
	return 0;
}