#include<bits/stdc++.h>
using namespace std;

const int N=1e3;
int size[N],parent[N];

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
	int n,q;
	cin>>n>>q;

	for(int i=1;i<=n;i++)
		make(i);

	while(q--)
	{
		int a,b;
		cin>>a>>b;
		Union(a,b);
	}
	int cnt=0;

	for(int i=1;i<=n;i++)
		if(find(i)==i)cnt++;
	cout<<cnt;
	return 0;
}