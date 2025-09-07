//this problem falls into unbounded knapsack category where we can choose the same instance more than once the code is all same just one minor change i.e after taking particular value we can choose again from the same ele or we can leave that element i.e t[i][j]=max(val[i-1]+t[i][j-len[i-1]],t[i-1][j])

//also in this case they didn't specify the possible cuts which we can do on the rod so we just considered 1-8 as the len of the rod is 8 so t[n+1][n+1] if they have specified the number of cuts will be 1 2 4 only then we would have formed t[n+1][len.size()+1 i.e 3+1]

#include<bits/stdc++.h>
using namespace std;

int rod(int *len,int * val,int i,int n)
{
	int t[n+1][n+1];

	for(int i=0;i<n+1;i++)
		for(int j=0;j<n+1;j++)
			if(i==0||j==0)
				t[i][j]=0;
	
	for(int i=1;i<n+1;i++)
	{
		for(int j=1;j<n+1;j++)
		{
			if(len[i-1]<=j)
				t[i][j]=max(val[i-1]+t[i][j-len[i-1]],t[i-1][j]);
			else
				t[i][j]=t[i-1][j];
		}
	}
	return t[n][n];
	
}

int rod(int *val,int n)
{
	vector<int> t(n+1,0);

	for(int len=1;i<=n;len++)
	{
		int ans=INT_MIN;
		for(int i=0;i<len;i++)
		{
			int cut=i+1;
			ans=max(ans,val[i]+t[len-cut]);
		}
		t[len]=ans;
	}
	return t[n];
}

int main()
{
	int n;
	cin>>n;

	int len[n],val[n];

	for(int i=0;i<n;i++)
	{
		len[i]=i+1;
		cin>>val[i];
	}

	cout<<rod(len,val,n,n);

	return 0;
}