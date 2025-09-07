#include<bits/stdc++.h>
using namespace std;
const int N=1e3;

int v,e;
vector<pair<int,int> > g[N];
vector<int> level(N,N);

void bfs(int v)
{
	deque<int> q;
	q.push_back(v);
	level[v]=0;

	while(!q.empty())
	{
		int ver=q.front();
		q.pop_front();

		for(auto child:g[ver])
		{
			int cv=child.first;
			int wt=child.second;

			if(level[ver]+wt<level[cv])
			{
				level[cv]=level[ver]+wt;
				if(wt==1)
					q.push_back(cv);
				else
					q.push_front(cv);
			}
		}
	}
	
}

int main()
{
	cin>>v>>e;

	for(int i=0;i<e;i++)
	{
		int a,b;
		cin>>a>>b;
		g[a].push_back({b,0});
		g[b].push_back({a,1});
	}
	bfs(1);
	cout<<level[v];
	return 0;
}	