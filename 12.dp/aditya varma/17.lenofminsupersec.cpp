//this program mergese the 2 strings in such a manner that it contains min number of char and will contain the lcs present in the 2 strings i.e aggtab gxtxayb here we can see gtab is the lcs after merging we can have aggtabgxtxayb but here the lcs is repeating twice so we can remove it i.e m+n-len(lcs) will result in the len of shortest commons supersequence 

#include<bits/stdc++.h>
using namespace std;

int lcs(string &a,string &b,int m,int n)
{
	int t[m+1][n+1];

	for(int i=0;i<m+1;i++)
		for(int j=0;j<n+1;j++)
			if(i==0||j==0)
				t[i][j]=0;

	for(int i=1;i<m+1;i++)
	{
		for(int j=1;j<n+1;j++)
		{
			if(a[i-1]==b[j-1])
				t[i][j]=1+t[i-1][j-1];
			else
				t[i][j]=max(t[i-1][j],t[i][j-1]);
		}
	}
	return t[m][n];
}

int main()
{
	string a,b;
	cin>>a>>b;

	cout<<a.size()+b.size()-lcs(a,b,a.size(),b.size());
	return 0;
}