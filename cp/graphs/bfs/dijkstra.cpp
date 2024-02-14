#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
vector<pair<int,int> > g[N];
vector<int> dist(N,N);
int vis[N];

void dijik(int src)
{
	set<pair<int,int> > s;
	dist[src]=0;
	s.insert(make_pair(0,src));
	while(s.size()>0)
	{
		auto p=*s.begin();
		s.erase(s.begin());
		int ver=p.second;

		if(vis[ver])continue;
		vis[ver]=1;

		for(auto child:g[ver])
		{
			int nv=child.first;
			int wt=child.second;

			if(dist[ver]+wt<dist[nv])
			{
				dist[nv]=dist[ver]+wt;
				s.insert(make_pair(dist[nv],nv));
			}
		}
	}
}

int main()
{
	int v,e;
	cin>>v>>e;
	for(int i=0;i<e;i++)
	{
		int a,b,wt;
		cin>>a>>b>>wt;
		g[a].push_back(make_pair(b,wt));
	}

	dijik(1);

	for(int i=1;i<=v;i++)
	{
		cout<<i<<" "<<dist[i]<<endl;
	}
	return 0;
}

