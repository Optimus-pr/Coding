#include<bits/stdc++.h>
using namespace std;

int parent[1e3];
int size[1e3];

void make(int i)
{
	parent[i]=i;
	size[i]=1;
}

void find(int i)
{
	if(parent[i]==i)
		return i;
	return parent[i]=find(parent[i]);
}

void Union(int a,int b)
{
	a=find(a);
	b=find(b);
	//the above 2 lines are must if not it will not work
	

	if(find(a)!=find(b))
	{
		if(size(a)<size(b))
			swap(a,b);
		parent[b]=a;
		size[a]+=size[b];
	}
}

int main()
{
	int n,m;

	cin>>n>>m;

	vector<pair<int,pair<int,int> > v;
	//we can also use prioqueue

	for(int i=0;i<m;i++)
	{
		int a,b,wt;
		cin>>a>>b>>wt;
		v.push_back({wt,{a,b}});
	}
	sort(v.begin(),v.end());

	for(int i=0;i<n;i++)
		make(i);

	int sum=0;

	for(auto & val:v)
	{
		int a=val.second.first,b=val.second.second,wt=val.first;
		if(find(a)!=find(b))
		{
			Union(a,b);
			sum+=wt;
		}
	}
	cout<<sum;
}