#include<bits/stdc++.h>
using namespace std;

int mindi(int *a,int n,int w)
{
	int t[n+1][w+1];

	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<w+1;j++)
		{
			if(i==0)
				t[i][j]=0;
			if(j==0)
				t[i][j]=1;
		}
	}

	for(int i=1;i<n+1;i++)
	{
		for(int j=1;j<w+1;j++)
		{
			if(a[i-1]<=j)
				t[i][j]=t[i-1][j-a[i-1]]||t[i-1][j];
			else 
				t[i][j]=t[i-1][j];
		}
	}
	
	int i=n;
	vector<int> v;
	for(int j=0;j<=w/2;j++)
		if(t[i][j]==1)
			v.push_back(j);

	
	return w-(2*v.back());

}

int main()
{
	int n;
	cin>>n;

	int sum=0;
	int a[n];
	
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	
	cout<<mindi(a,n,sum);
}