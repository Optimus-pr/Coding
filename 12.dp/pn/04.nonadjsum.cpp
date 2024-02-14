//no 2 adjacent houses can be robbed 
#include<bits/stdc++.h>
using namespace std;

// int main()
// {
// 	int a[]={6,10,12,7,9,14};
// 	int dp[6];
// 	dp[0]=a[0];
// 	dp[1]=max(a[0],a[1]);

// 	for(int i=2;i<6;i++)
// 	{
// 		dp[i]=max(dp[i-1],a[i]+dp[i-2]);
// 	}

// 	cout<<dp[5];
// 	return 0;
// }

int main()
{
	int a[]={6,10,12,7,9,14};
	int prev2=0,prev=a[0],cur;

	for(int i=1;i<6;i++)
	{
		int take=a[i];
		if(i>1)
			take+=prev2;
		int notake=prev;

		cur=max(take,notake);
		prev2=prev;
		prev=cur;
	}
	cout<<prev;
	return 0;
}

//house robber-2

//houses are arrange in circular manner i.e first and last are neigbhours here also no to adjacent houses can be robbed;

int rob(int *a,n)
{
	int prev2=0,prev=a[0],cur;

	for(int i=1;i<n;i++)
	{
		int take=a[i];
		if(i>1)
			take+=prev2;
		int notake=prev;

		cur=max(take,notake);
		prev2=prev;
		prev=cur;
	}
	cout<<prev;
	return 0;
}

int main()
{
	int n;
	cin>>n;

	int a[n];

	for(int i=0;i<n;i++)
		cin>>a[i];

	vector<int> t1,t2;

	for(int i=0;i<n;i++)
	{
		if(i!=0)t1.push_back(a[i]);
		if(i!=n)t2.push_back(a[i]);
	}

	cout<<max(rob(t1,n-1),rob(t2,n-1));
	return 0;

}


