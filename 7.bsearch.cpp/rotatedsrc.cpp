#include<bits/stdc++.h>
using namespace std;

// int srch(int *a,int key, int n)
// {
// 	int l=0,h=n-1,mid;

// 	while(l<=h)
// 	{
// 		mid=(h+l)/2;
// 		if(a[mid]==key)
// 			return mid;
		
// 		else if(a[mid]>a[l])left
// 		{
// 			if(key>=a[l] && key<a[mid])
// 				h=mid-1;
// 			else
// 				l=mid+1;
// 		}
// 		else {right
// 			if(key>a[mid] && key<=a[h])
// 				l=mid+1;
// 			else
// 				h=mid-1;
// 		}
// 	}
// 	if(l>h)
// 		return -1;
// 	else
// 		return mid;
// }

int mini(int *a,int l,int h)
{
	int mid,n=h-l+1;
	if(a[l]<=a[h])
		return 0;
	while(l<=h)
	{
		mid=h+(l-h)/2;
		int prev=a[(mid-1+n)%n];
		int next=a[(mid+1)%n];

		if(a[mid]<=prev && a[mid]<=next)
			return mid;
		else if(a[mid]<=a[h])//note this is to be checked before next condi min element always lies in the unsorted part
			h=mid-1;
		else if(a[l]<=a[mid])
			l=mid+1;
		

	}
	return 0;
}

int bs(int *a,int l,int h,int key)
{
	int mid,temp=-1;

	while(l<=h)
	{
		mid=h +(l-h)/2;
		if(a[mid]==key)
			return mid;
		else if(a[mid]>key)
			h=mid-1;
		else
			l=mid+1;
	}
	return -1;
}


int main()
{
	int n,key;
	cin>>n;

	int a[n];

	for(int i=0;i<n;i++)
		cin>>a[i];

	cin>>key;

	if(a[0]<a[n-1])
	{
		cout<<bs(a,0,n-1,key);
		return 0;
	}
	else
	{
		int minele=mini(a,0,n-1);
		
		if(a[minele]==key)
		{
			cout<<minele;
			return 0;
		}


		int l=bs(a,0,minele-1,key);
		int r=bs(a,minele+1,n-1,key);
		if(l==r && l==-1)
			cout<<"Element not found";
		else if(l==-1)
			cout<<r;
		else if(r==-1)
			cout<<l;
	}

	return 0;
}