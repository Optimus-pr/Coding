#include<bits/stdc++.h>
using namespace std;
int m;
vector<int> v;

bool is_suff(int ht)
{
	int sum=0;
	for(int i=0;i<v.size();i++)
	{
		if(v[i]>=ht)
			sum+=(v[i]-ht);
	}
	return sum>=m;
}

int main()
{
	int n;
	cin>>n>>m;
	int l=0,h,mid;


	for(int i=0;i<n;i++)
	{
		int ele;
		cin>>ele;
		v.push_back(ele);
	}
	h=*max_element(v.begin(),v.end());

	while(h-l>1)
	{
		mid=(h+l)/2;
		if(is_suff(mid))
			l=mid;
		else
			h=mid-1;
	}

	if(is_suff(h))
		cout<<h<<endl;
	else
		cout<<l<<endl;
	return 0;
}