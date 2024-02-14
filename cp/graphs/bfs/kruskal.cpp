#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
int parent[N],size[N];

void make(int n)
{
	parent[n]=n;
	size[n]=1;
}

int find(int n)
{
	if(n==parent[n])return n;
	return parent[n]=find(parent[n]);
}

void Union(int a,int b)
{
	a=find(a);
	b=find(b);
	if(a!=b)
	{
		if(size[a]<size[b])
			swap(a,b);
		parent[b]=a;
		size[a]+=size[b];
	}
}

int main()
{
	int ver,e;
	cin>>ver>>e;
	vector<pair<int,pair<int,int> > > v;
	for(int i=0;i<e;i++)
	{
		int a,b,wt;
		cin>>a>>b>>wt;
		v.push_back({wt,{a,b}});
	}
	for(int i=1;i<=ver;i++)
		make(i);

	sort(v.begin(),v.end());

	int tot=0;

	for(auto val:v)
	{
		int wt=val.first;
		int a=val.second.first;
		int b=val.second.second;
		if(find(a)!=find(b))
		{
			Union(a,b);
			cout<<a<<" "<<b<<" "<<wt<<endl;
			tot+=wt;
		}
	}
	cout<<tot<<endl;
	return 0;
}