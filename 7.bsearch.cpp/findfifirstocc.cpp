#include<bits/stdc++.h>
using namespace std;

// int main()
// {
// 	int n,key;
// 	cin>>n;

// 	int a[n];

// 	for(int i=0;i<n;i++)
// 		cin>>a[i];
// 	cin>>key;

// 	int ind=lower_bound(a,a+n,key)-a;

// 	if(ind!=n && a[ind]==key)cout<<ind;
// 	else
// 		cout<<"-1";
// }

int bs(int *a,int l,int h,int key)
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

int main()
{
	int n,key;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	cin>>key;

	cout<<bs(a,0,n-1,key);
	return 0;
}