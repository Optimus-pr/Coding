#include<bits/stdc++.h>
using namespace std;
const int N=1e3;

int level[N][N];
int vis[N][N];

int getX(string s)
{
	return s[0]-'a';
}

int getY(string s)
{
	return s[1]-'1';
}

vector<pair<int,int> > v={{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};

bool isvalid(int x,int y)
{
	if(x<0 || y<0)return false;
	if(x>7 || y>7)return false;
	return true;
}

int bfs(string s,string d)
{
	int sx=getX(s);
	int sy=getY(s);

	int dx=getX(d);
	int dy=getY(d);

	queue<pair<int,int> > q;
	q.push(make_pair(sx,sy));
	vis[sx][sy]=1;

	while(!q.empty())
	{
		pair<int,int> p=q.front();
		q.pop();

		int x=p.first,y=p.second;

		for(auto &val:v)
		{
			int nx=x+val.first;
			int ny=y+val.second;

			if(isvalid(nx,ny))
			{
				q.push(make_pair(nx,ny));
				vis[nx][ny]=1;
				level[nx][ny]=level[x][y]+1;
			}
		}
		if(level[dx][dy]!=0)
			return level[dx][dy];

	}
	return level[dx][dy];

}

int main()
{
	string s,d;
	cin>>s>>d;

	cout<<bfs(s,d);
	return 0;
}