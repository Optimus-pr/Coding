#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,key;
	cin>>n;
	vector<int> v(n);

	for(int i=0;i<n;i++)
		cin>>v[i];
	cin>>key;

	int l=0,h=n-1,mid;


	// this is for lower bound
	// while(h-l>1)
	// {
	// 	mid=(h+l)/2;

	// 	if(v[mid]<key)
	// 		l=mid+1;
	// 	else
	// 		h=mid;
	// }

	if(v[l]>=key)
		cout<<v[l];
	else if(v[h]>=key)
		cout<<v[h];
	else 
		cout<<"-1";

	// for upper bound
	// while(h-l>1)
	// {
	// 	mid=(h+l)/2;
	// 	if(v[mid]<=key)
	// 		l=mid+1;
	// 	else
	// 		h=mid;
	// }

	// if(v[l]>key)
	// 	cout<<v[l];
	// else if(v[h]>key)
	// 	cout<<v[h];
	// else 
	// 	cout<<"-1";

	return 0;


	//using inbuilt fn

	// int index=lower_bound(a,a+n,key)-a;
	// int index=upper_bound(a,a+n,key)-a;
	// bool flag=binary_search(a,a+n,key);

	
}