#include<bits/stdc++.h>
using namespace std;

int ub(vector<int> &v,int key)
{
	int l=0,h=v.size()-1,mid;

	while(h-l>1)
	{
		mid=(h+l)/2;

		if(v[mid]<=key)
			l=mid+1;
		else
			h=mid;
	}

	if(v[l]>key)
		return l;
	else if(v[h]>key)
		return h;
	else 
		return -1;
}

int main()
{
	int n;
	cin>>n;

	vector<int> v(n);

	for(int i=0;i<n;i++)
		cin>>v[i];

	cout<<(upper_bound(v.begin(),v.end(),4))-v.begin();
	cout<<(upper_bound(v.begin(),v.end(),7))-v.begin();
	cout<<(upper_bound(v.begin(),v.end(),10))-v.begin();

	// cout<<ub(v,4);
	// cout<<ub(v,7);
	// cout<<ub(v,10);
}