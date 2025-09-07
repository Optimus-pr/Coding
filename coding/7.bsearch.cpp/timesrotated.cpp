//this tells how may times a sorted array is to be rotated 
//it can be found be finding the index of min ele
//note min ele will always lie in the unsorted part of the array 
#include<iostream>
using namespace std;

int bs(int *a,int l,int h)
{
	int mid,n=h+1;
	if(a[l]<=a[h])
		return 0;
	while(l<=h)
	{
		mid=h+(l-h)/2;
		int prev=a[(mid-1+n)%n];
		int next=a[(mid+1)%n];

		if(a[mid]<=prev && a[mid]<=next)
			return mid;
		else if(a[mid]<=a[h])//note this is to be checked before next condi
			h=mid-1;
		else if(a[l]<=a[mid])
			l=mid+1;
		

	}
	return 0;
}

int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	

	cout<<bs(a,0,n-1);

	return 0;
}