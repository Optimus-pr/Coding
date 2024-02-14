#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
vector<int> g[N];
int vis[N];
int cycle=0;

void dfs(int v,int p=-1)
{
	vis[v]=1;
	cout<<v<<endl;
	for(auto child:g[v])
	{
		if(vis[child] && child==p)continue;
		if(vis[child])
		{
			cycle++;
			return;
		}
		dfs(child,v);
	}
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

	int connected=0;
	dfs(0);
	// for(int i=0;i<v;i++)
	// {
	// 	if(vis[i])continue;
	// 	dfs(i);
	// 	connected++;
	// }
	cout<<connected<<" "<<cycle<<endl;
	return 0;

}