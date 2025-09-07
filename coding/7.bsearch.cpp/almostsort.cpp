#include<iostream>
using namespace std;

int bs(int *a,int l,int h,int key)
{
	int mid;

	while(l<=h)
	{
		mid=h+(l-h)/2;

		if(a[mid]==key)
			return mid;
		else if(mid-1>=l && a[mid-1]==key)
			return mid-1;
		else if(mid+1<=h && a[mid+1]==key)
			return mid+1;

		else if(a[mid]<key)
			l=mid+2;
		else
			h=mid-2;
	}
	return -1;
}

int main()
{
	int n;
	cin>>n;

	int a[n];

	for(int i=0;i<n;i++)
		cin>>a[i];

	int key;
	cin>>key;

	cout<<bs(a,0,n-1,key);

}