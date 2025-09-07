#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
int wt[N];
int val[N];
int dp[N][N];

int knap(int index,int cap)
{

	if(dp[index][cap]!=-1)return dp[index][cap];

	if(index<0||cap==0)return 0;

	int ans=knap(index-1,cap);

	if(cap-wt[index]>=0)
	ans=max(ans,knap(index-1,cap-wt[index])+val[index]);
	return dp[index][cap]=ans;

}

int main()
{
	memset(dp,-1,sizeof(dp));
	int cap,n;
	cin>>n>>cap;

	for(int i=0;i<n;i++)
		cin>>wt[i]>>val[i];

	cout<<knap(n-1,cap);
	return 0;
}