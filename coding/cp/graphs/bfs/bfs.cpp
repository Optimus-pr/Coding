#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
vector<int> g[N];
int vis[N],level[N];

void bfs(int v)
{
	queue<int> q;
	q.push(v);
	vis[v]=1;
	
	while(!q.empty())
	{
		int ver=q.front();
		q.pop();
		for(auto child:g[ver])
		{
			if(vis[child])continue;
			q.push(child);
			vis[child]=1;
			level[child]=level[ver]+1;
		}
	}
}

int main()
{
	int v,e;
	cin>>v;

	for(int i=0;i<v-1;i++)
	{
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
		
	}
	bfs(1);
	cout<<endl;
	for(int i=1;i<=v;i++)
	{
		cout<<i<<":"<<level[i]<<endl;
	}
	return 0;
}