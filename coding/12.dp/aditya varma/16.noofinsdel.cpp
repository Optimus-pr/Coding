//here main is to find the number of insertions and deletions required for string a to be converted into string b i.e for heap ->pea we need to del h,p and insert p at the end i.e the total number of insertion are len(a)-lcs number of deletion required are len(b)-lcs

#include<bits/stdc++.h>
using namespace std;

int lcs(string &a,string &b,int m,int n)
{
	int t[m+1][n+1];

	for(int i=0;i<m+1;i++)
		for(int j=0;j<n+1;j++)
			if(i==0 || j==0)
				t[i][j]=0;

	for(int i=1;i<m+1;i++)
	{
		for(int j=1;j<n+1;j++)
		{
			if(a[i-1]==b[i-1])
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

	lcs(a,b,a.size(),b.size());
}