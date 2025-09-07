//this will return if the subset corresponding the given sum exists or not

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,w;
	cin>>n>>w;

	int a[n],t[n+1][w+1];

	for(int i=0;i<n;i++)
		cin>>a[i];

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
			if(a[i-1]<=w)
				t[i][j]=(t[i-1][j-a[i-1]])||(t[i-1][j]);
			else
				t[i][j]=t[i-1][j];
		}
	}
	
	cout<<t[n][w];
}