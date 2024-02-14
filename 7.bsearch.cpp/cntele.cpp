#include<iostream>
using namespace std;

int left(int *a,int l,int h,int key)
{
	int mid,temp=-1;

	while(l<=h)
	{
		mid=h +(l-h)/2;
		if(a[mid]==key)
		{
			temp=mid;
			h=mid-1;
		}
		else if(a[mid]>key)
			h=mid-1;
		else
			l=mid+1;
	}
	return temp;
}

int right(int *a,int l,int h,int key)
{
	int mid,temp=-1;

	while(l<=h)
	{
		mid=h +(l-h)/2;
		if(a[mid]==key)
		{
			temp=mid;
			l=mid+1;
		}
		else if(a[mid]>key)
			h=mid-1;
		else
			l=mid+1;
	}
	return temp;
}

int main()
{
	int n,key;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	cin>>key;

	int l=left(a,0,n-1,key);
	int r=right(a,0,n-1,key);

	if(l==-1)
		cout<<"Element not found\n";
	else if(l==r)
		cout<<"1";
	else
		cout<<r-l+1;

	return 0;
}