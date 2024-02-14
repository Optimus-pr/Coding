#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > vis(3,vector<int>(3,0));
int cnt=0;

void dfs(int x,int y,char c,char a[][3])
{
	if(x<0 || y<0 || x>=3 || y>=3)
		return;
	if(vis[x][y] || a[x][y]!=c)
		return;

	vis[x][y]=1;
	cnt++;

	dfs(x+1,y,c+1,a);
	dfs(x-1,y,c+1,a);
	dfs(x,y+1,c+1,a);
	dfs(x,y-1,c+1,a);
	dfs(x-1,y-1,c+1,a);
	dfs(x+1,y+1,c+1,a);
	dfs(x+1,y-1,c+1,a);
	dfs(x-1,y+1,c+1,a);
}


int main()
{
	char ch;
	cin>>ch;
	int x=-1,y=-1;

	char a[][3]={{'d','b','i'},{'c','e','g'},{'a','h','f'}};
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			if(a[i][j]==ch)
			{
				x=i;y=j;break;
			}
	
	if(x==-1 && y==-1)
		cout<<-1;
	else
	{
		dfs(x,y,ch,a);
		cout<<cnt;
	}
	return 0;
}