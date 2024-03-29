#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
int dp[N];

int fib(int n)
{
	if(n==0)return 0;
	if(n==1)return 1;
	if(dp[n]!=-1)return dp[n];//this is called as  memoization

	return dp[n]=fib(n-2)+fib(n-1);
}


int main()
{
	memset(dp,-1,sizeof(dp));
	int n;
	cin>>n;
	cout<<fib(n);
	return 0;
}