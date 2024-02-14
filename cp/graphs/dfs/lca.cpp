#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
vector<int> g[N];
int par[N];

void dfs(int v,int p=-1)
{
	for(auto child:g[v])
	{
		if(child==p)continue;
		par[child]=v;
		dfs(child,v);
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
	par[1]=-1;
	dfs(1);

	int m,n,i;
	cin>>m>>n;
	vector<int> v1,v2;

	while(m!=-1)
	{
		v1.push_back(m);
		m=par[m];
	}

	while(n!=-1)
	{
		v2.push_back(n);
		n=par[n];
	}

	reverse(v1.begin(),v1.end());
	reverse(v2.begin(),v2.end());

	int size=v1.size();
	if(size>v2.size())
		size=v2.size();
	for(i=0;i<size;i++)
	{
		if(v1[i]==v2[i])continue;
		break;
	}
	cout<<v1[i-1];
	return 0;
}