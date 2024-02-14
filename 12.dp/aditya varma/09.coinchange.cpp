#include<bits/stdc++.h>
using namespace std;
//maximum no of ways to reach the denomination
int coins(int *coin,int n,int amt)
{
	int t[n+1][amt+1];

	for(int i=0;i<n+1;i++)
		for(int j=0;j<amt+1;j++)
		{
			if(i==0)
				t[i][j]=0;
			if(j==0)
				t[i][j]=1;
		}

	for(int i=1;i<n+1;i++)
	{
		for(int j=1;j<amt+1;j++)
		{
			if(coin[i-1]<=j)
				t[i][j]=t[i-1][j]+t[i][j-coin[i-1]];
			else
				t[i][j]=t[i-1][j];
		}
	}
	return t[n][amt];
}

//minimum no of coins required to reach the denomination
int coins(int *coin,int amt)
{
	int dp[amt+1];
	dp[0]=0;

	for(int i=1;i<=amt;i++)
	{
		dp[i]=99999;
		for(auto &c:coin)
		{
			if(i-c>=0 && dp[i-c]!=99999)
				dp[i]=min(dp[i],dp[i-c]+1);
		}
	}

	return dp[amt]!=99999?dp[amt]:-1;
}

int main()
{
	int n,amt;
	cin>>n>>amt;

	int coin[n];

	for(int i=0;i<n;i++)
		cin>>coin[i];

	cout<<coins(coin,amt);


}