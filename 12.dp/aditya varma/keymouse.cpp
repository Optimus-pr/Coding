#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m,x;
	cin>>n>>m>>x;
	int key[n],mou[m];
	for(int i=0;i<n;i++)
		cin>>key[i];

	for(int i=0;i<m;i++)
		cin>>mou[i];

	int t[n+1][m+1];

	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			if(i==0 || j==0)
				t[i][j]=0;
		}
	}
	int mx=-9999;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			int val=key[i-1]+mou[j-1];
			int a=t[i-1][j];
			int b=t[i-1][j-1];
			int c=t[i][j-1];
			if(val<=x)
			{
				mx=max(val,max(max(a,b),c));
				t[i][j]=mx;
			}
			else
			{
				
				t[i][j]=max(a,max(b,c));
			}
		}
	}
	cout<<t[n][m]<<endl;
	return 0;
}