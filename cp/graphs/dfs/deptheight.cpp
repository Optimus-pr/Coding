#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
vector<int> g[N];
int ht[N];
int dpt[N];

void dfs(int v,int p=-1)
{
	for(auto child:g[v])
	{
		if(child==p)continue;
		dpt[child]=dpt[v]+1;
		dfs(child,v);
		ht[v]=max(ht[v],ht[child]+1);
	}
}

int main()
{
	int v;
	cin>>v;

	for(int i=0;i<v-1;i++)
	{
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(1);

	for(int i=1;i<=v;i++)
	{
		cout<<i<<" "<<dpt[i]<<" "<<ht[i]<<endl;
	}
	return 0;
}