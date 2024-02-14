//searching in descending orddr

#include<iostream>
using namespace std;


int bs(int *a,int l,int h,int key)
{
	int mid;

	while(l<=h)
	{
		mid=h +(l-h)/2;
		if(a[mid]==key)
			return mid;
		else if(a[mid]>key)
			l=mid+1;
		else
			h=mid-1;
	}
	return -1;
}

int main()
{
	int n,key;
	cin>>n>>key;

	int a[n];

	for(int i=0;i<n;i++)
		cin>>a[i];

	cout<<bs(a,0,n-1,key);
}