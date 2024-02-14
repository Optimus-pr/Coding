// 1 5 11 5 here the sum is 22 which is even implies there is possiblity that we may find subsets summing up to 11 here 5 5 1 and 11 are the 2 subsets which sum up to form the sum 22 if sum was odd then it was not possible to equaly do partition of the array if even then we can call the same subsetsum problem which is addresed before

#include<bits/stdc++.h>
using namespace std;

bool chk(int *a,int n,int w)
{
	int t[n+1][w+1];

	for(int i=0;i<n+1;i++)
		for(int j=0;j<w+1;j++)
		{
			if(i==0)
				t[i][j]=0;
			if(j==0)
				t[i][j]=1;
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
	return t[n][w];
}

int main()
{
	int n,w,sum=0;
	cin>>n;

	int a[n];

	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}

	if(sum&1)
		cout<<"0";
	else
		cout<<chk(a,n,sum/2);

}