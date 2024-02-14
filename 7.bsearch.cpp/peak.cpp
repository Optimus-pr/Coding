//the same sol is for find the max val in bitonic array where bitonic array is the one which starts increasing after one point it will start decreasing

#include<bits/stdc++.h>
using namespace std;

int peak(int *a,int l,int h)
{
	int mid,n=h+1;

	while(l<=h)
	{
		mid=h+(l-h)/2;

		if(mid>0 && mid<n-1)
		{
			if(a[mid]>a[mid-1] && a[mid]>a[mid+1])
				return mid;
			else
			{
				if(a[mid]<a[mid+1])
					l=mid+1;
				else
					h=mid-1;
			}
		}
		else if(mid==0)
		{
			if(a[0]>a[1])
				return 0;
			else
				return 1;
		}
		else if(mid==n-1)
		{
			if(a[n-1]>a[n-2])
				return n-1;
			else
				return n-2;
		}
	}
}

int main()
{
	int n;
	cin>>n;

	int a[n];

	for(int i=0;i<n;i++)
		cin>>a[i];

	cout<<peak(a,0,n-1);

	return 0;
}