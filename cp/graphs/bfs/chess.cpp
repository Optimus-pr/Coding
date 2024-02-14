#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
int vis[N][N];
int level[N][N];

int xtract(string s)
{
	return s[0]-'a';
}

int ytract(string s)
{
	return s[1]-'1';
}

vector<pair<int,int> > movements={{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};

bool isValid(int x,int y)
{
	if(x<0||y<0||x>=8||y>=8||vis[x][y])return false;
	return true;
}

void bfs(string s,string d)
{
	int sx=xtract(s);
	int sy=ytract(s);

	int dx=xtract(d);
	int dy=ytract(d);

	queue<pair<int,int> > q;
	q.push({sx,sy});
	vis[sx][sy]=1;

	while(!q.empty())
	{
		auto p=q.front();
		q.pop();
		int x=p.first;
		int y=p.second;
		
		for(auto move:movements)
		{
			int nx=x+move.first;
			int ny=y+move.second;

			if(isValid(nx,ny))
			{
				q.push({nx,ny});
				vis[nx][ny]=1;
				level[nx][ny]=level[x][y]+1;
			}
		}
		if(level[dx][dy]!=0)
		{
			cout<<level[dx][dy];
			return;
		}
	}
}


int main()
{
	string s,d;
	cin>>s>>d;

	bfs(s,d);
	return 0;
}