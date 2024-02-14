#include<bits/stdc++.h>
using namespace std;
const int n=1e3;

vector<pair<int,int> > g[n];
vector<int> level(n,n);

int e,ver;

int bfs(int v)
{
	deque<int> q;
	q.push_front(v);
	level[v]=0;

	while(!q.empty())
	{
		int ver=q.front();
		q.pop_front();

		for(auto &child:g[ver])
		{
			int child_v=child.first;
			int wt=child.second;

			if(level[ver]+wt<level[child_v])
			{
				level[child_v]=level[ver]+wt;

				if(wt==0)
					q.push_front(child_v);
				else
					q.push_back(child_v);
			}
		}
	}
	return level[ver]== n ? -1 : level[ver];
}

int main()
{
	cin>>ver>>e;

	for(int i=0;i<e;i++)
	{
		int a,b;
		cin>>a>>b;

		g[a].push_back(make_pair(b,0));
		g[b].push_back(make_pair(a,1));
	}

	cout<<bfs(1);

	return 0;
}