//this code finds the number of right angled triangle formed given set of points

#include<bits/stdc++.h>
using namespace std;

int cnttriangle(vector<pair<int,int> > &v,int n)
{
	int ans=0;
	unordered_map<int,int> fx,fy;

	for(auto &val:v)
	{
		int a=val.first,b=val.second;
		fx[a]++;
		fy[b]++;
	}

	for(auto &val:v)
	{
		int x=val.first,y=val.second;
		
		ans+=(fx[x]-1)*(fy[y]-1);
	}
	return ans;
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
	cout<<cnttriangle(v,n);

}