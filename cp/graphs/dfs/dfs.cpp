#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
vector<int> g[N];
int vis[N];

void dfs(int ver)
{
	vis[ver]=1;
	//take action on vertex after entering the vertex
	for(auto child:g[ver])
	{
		if(vis[child])continue;
		//take action on child before entering the child
		dfs(child);
		//take action on child after exiting the child
	}
	//take action on vertex before exiting the vertex
}


int main()
{
	int v,e;
	cin>>v>>e;

	for(int i=0;i<e;i++)
	{
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	dfs(0);
	return 0;
}