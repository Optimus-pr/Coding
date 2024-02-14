#include<bits/stdc++.h>
using namespace std;

string scs(string &a,string &b,int m,int n)
{
	string c="";

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

	int i=m,j=n;
	while(i>0 && j>0)
	{
		if(a[i-1]==b[j-1])
		{
			c.push_back(a[i-1]);
			i--;j--;
		}
		else
		{
			if(t[i-1][j]>t[i][j-1])
			{
				c.push_back(a[i-1]);
				i--;
			}
			else
			{
				c.push_back(b[j-1]);
				j--;
			}

		}
	}

	while(i>0)
	{
		c.push_back(a[i-1]);
		i--;
	}

	while(j>0)
	{
		c.push_back(a[j-1]);
		j--;
	}

	return c;

}

int main()
{
	string a,b;
	cin>>a>>b;

	string c=scs(a,b,a.size(),b.size());
	reverse(c.begin(),c.end());

	cout<<c;
	return 0;


}