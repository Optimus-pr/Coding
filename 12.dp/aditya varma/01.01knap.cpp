#include<bits/stdc++.h>
using namespace std;

int dp[10][10];

int knap(int *wt,int *val,int w,int i)
{
	if(i==0||w==0)
		return 0;

	if(dp[i][w]!=-1)
		return dp[i][w];

	if(wt[i-1]<=w)
		return dp[i][w]=max(val[i-1]+knap(wt,val,w-wt[i-1],i-1),knap(wt,val,w,i-1));
	else if(wt[i-1]>w)
		return dp[i][w]=knap(wt,val,w,i-1);
}

int main()
{
	int n,w;
	cin>>n>>w;

	memset(dp,-1,sizeof(dp));

	int wt[n],val[n];

	for(int i=0;i<n;i++)
		cin>>wt[i]>>val[i];

	cout<<knap(wt,val,w,n);

}