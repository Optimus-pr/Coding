#include<bits/stdc++.h>
using namespace std;
int dp[10]={0};

int minsteps(int *a,int n,int i)
{
	if(i==n-1)
		return 0;

	if(i>=n)
		return 999;

	if(dp[i]!=0)
		return dp[i];

	int max_jumps=a[i];
	int steps=999;

	for(int jump=1;jump<=max_jumps;jump++)
	{
		int subprob=minsteps(a,n,i+jump);
		if(subprob!=999)
			steps=min(steps,subprob+1);
	}
	return dp[i]=steps;
}

int main()
{
	int a[]={10,4,2,1,2,3,7,1,1,3};
	int n=10;
	cout<<minsteps(a,n,0);
	return 0;
}