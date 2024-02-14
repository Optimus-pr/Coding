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

	sort(v.begin(),v.end());

	int l=0,h=n-1,mid;
	while(h-l>1)
	{
		mid=(h+l)/2;
		if(v[mid]<key)
			l=mid+1;
		else
			h=mid;
	}

	if(v[l]==key)
		cout<<l<<endl;
	else if(v[h]==key)
		cout<<h<<endl;
	return 0;
}