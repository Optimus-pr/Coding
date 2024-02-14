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
	//the above 2 lines are must
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

	for(int i=0;i<n;i++)
		make(i);

	while(m--)
	{
		int a,b;
		cin>>a>>b;

		Union(a,b);
	}

	int cnt=0;
	for(int i=0;i<n;i++)
	{
		if(i==find(i))//to check the connected components 
			cnt++;
	}
	cout<<cnt;
}