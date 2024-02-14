#include<bits/stdc++.h>
using namespace std;

int cntrec(vector<pair<int,int> > &v,int n)
{
	int ans=0;
	set<pair<int,int> > u;

	for(auto &it:v)
		u.insert(it);

	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			int a=v[i].first,b=v[i].second,c=v[j].first,d=v[j].second;
			if(c==a || b==d)
				continue;
			if(u.find(make_pair(a,d))!=u.end() && u.find(make_pair(c,b))!=u.end())
				ans+=1;
		}
	}
	return ans/2;
}

int main()
{
	int n;
	cin>>n;

	vector<pair<int,int> > v;

	for(int i=0;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		v.push_back(make_pair(a,b));
	}
	cout<<cntrec(v,n);

}