#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
int val[N][N];
int vis[N][N];
int level[N][N];
int m,n;

vector<pair<int,int> > movements={{0,1},{1,0},{0,-1},{-1,0}};

bool isValid(int x,int y)
{
	if(x<0 || y<0 || x>=m ||y>=m ||vis[x][y])return false;
	return true;
}

int bfs()
{
	queue<pair<int,int> > q;
	int ans=0,mx;
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			mx=max(mx,val[i][j]);

	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(val[i][j]==mx)
			{
				q.push({i,j});
				vis[i][j]=1;
			}
		}
	}

	while(!q.empty())
	{
		auto p=q.front();
		q.pop();
		int x=p.first;
		int y=p.second;

		for(auto move:movements)
		{
			int nx=move.first+x;
			int ny=move.second+y;

			if(isValid(nx,ny))
			{
				q.push({nx,ny});
				vis[nx][ny]=1;
				level[nx][ny]=level[x][y]+1;
				ans=max(ans,level[nx][ny]);
			}
		}
	}
	return ans;
}

int main()
{
	cin>>m>>n;

	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			cin>>val[i][j];
	cout<<bfs();
	return 0;
}