#include<bits/stdc++.h>
using namespace std;
const int N=1e3;;
vector<int> v(N);
int dp[N];

int lis(int n)//due to dp the number of call is reduced to n from expo and in each call aproximatedly n time is taken which implies in together the total complexity is n^2
{
	int ans=1;

	if(dp[n]!=-1)return dp[n];

	for(int i=0;i<n;i++)
	{
		if(v[n]>v[i])
			ans=max(ans,lis(i)+1);
	}
	return dp[n]=ans;
}

int main()
{
	memset(dp,-1,sizeof(dp));
	int num;
	cin>>num;
	int ans=0;
	for(int i=0;i<num;i++)
		cin>>v[i];

	for(int i=0;i<num;i++)
	// for(int i=num-1;i>=0;i--)
		ans=max(ans,lis(i));
	cout<<ans;
	return 0;
}