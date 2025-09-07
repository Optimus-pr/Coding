//bitonic array is an array where ele start to increase upto a point and there after they start to decrease so we need to find the peak first there after apply bs for asc in left side and bs for des in right side

#include<iostream>
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
			if(a[0]<a[1])
				return 1;
			else
				return 0;
		}
		else if(mid==n-1)
		{
			if(a[mid]>a[mid-1])
				return mid;
			else
				return mid-1;
		}
	}
}

int lbs(int * a,int l,int h,int key)
{
	int mid;

	while(l<=h)
	{
		mid=h+(l-h)/2;

		if(a[mid]==key)
			return mid;
		else if(a[mid]>key)
			h=mid-1;
		else
			l=mid+1;
	}
	return -1;
}

int rbs(int * a,int l,int h,int key)
{
	int mid;

	while(l<=h)
	{
		mid=h+(l-h)/2;

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
	int n;
	cin>>n;

	int a[n];

	for(int i=0;i<n;i++)
		cin>>a[i];

	int key;
	cin>>key;

	int pk=peak(a,0,n-1);
	cout<<pk<<endl;
	if(a[pk]==key)
	{
		cout<<pk;
		return 0;
	}

	int left=lbs(a,0,pk-1,key);
	int right=rbs(a,pk+1,n-1,key);

	if(left==right && left==-1)
		cout<<"Element not found";
	else if(left==-1)
		cout<<right;
	else 
		cout<<left;

	return 0;
}