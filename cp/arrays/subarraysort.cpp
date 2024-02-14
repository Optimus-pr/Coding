#include<bits/stdc++.h>
using namespace std;

bool check(vector<int> &v,int i)
{
	if(i==0 )
		return v[i]>v[i+1];
	
	if(i==v.size()-1 )
    	return v[i]<v[i-1];
	
	return v[i]<v[i-1]||v[i]>v[i+1];

}

pair<int,int> compute(vector<int> &v )
{
	int mx=-999;
	int mn=999;
	for(int i=0;i<v.size();i++)
	{
		if(check(v,i))
		{
			mx=max(mx,v[i]);
			mn=min(mn,v[i]);
		}
	}

	if(mx==-999)
		return {-1,-1};
	int i=0;
	while(mn>=v[i])
		i++;
	int j=v.size()-1;
	while(mx<=v[j])
		j--;
	return {i,j};
}

int main()
{
	int n;
	cin>>n;

	vector<int> v(n);

	for(int i=0;i<n;i++)
		cin>>v[i];

	pair<int,int> p=compute(v);

	cout<<p.first<<" and "<<p.second<<endl;
	return 0;
}