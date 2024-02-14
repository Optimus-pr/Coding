//the aim is to find the max subarray sum where the sub array can contain only 3 elements;
#include<bits/stdc++.h>
using namespace std;

int msum(int *a,int n)
{
	int i=0,j=0,sum=0,msum=0;

	while(j<n)
	{
		sum+=a[j];
		if(j-i+1<3)
			j++;
		else if(j-i+1==3)
		{
			msum=max(sum,msum);
			sum-=a[i];
			i++;
			j++;
		}
	}
	return msum;
}


int main()
{
	int n;
	cin>>n;

	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];

	cout<<msum(a,n);
}