//longest palindromic subsequence here we will be given with a string and our aim is to return a longest palindromic subsequece till now we tryied solving problems containing 2 strings but here in this case we are only given with single string so we need to derive another string ourselves by reversing the first string

#include<bits/stdc++.h>
using namespace std;

int lpc(string a,string b)
{
	int m=a.size(),n=m;

	int t[m+1][n+1];

	for(int i=0;i<m+1;i++)
		for(int j=0;j<n+1;j++)
			if(i==0 || j==0)
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
	string a;
	cin>>a;
	string b=a;
	reverse(b.begin(),b.end());
	cout<<lpc(a,b);
	

	return 0;
}