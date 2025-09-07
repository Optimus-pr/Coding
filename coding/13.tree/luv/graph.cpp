#include<bits/stdc++.h>
using namespace std;
const int n=1e3;

vector<int> g[n];
bool vis[n];
vector<vector<int> > v;
vector<int> temp;


// void dfs(int ver)
// {
// 	vis[ver]=1;
// 	temp.push_back(ver);
// 	for(auto &child:g[ver])
// 	{
// 		if(vis[child])continue;
// 		dfs(child);
// 	}
// }

bool dfs(int ver,int p)
{
	vis[ver]=1;
	bool isloop=false;
	for(auto &child:g[ver])
	{
		if(vis[child] && child==p)continue;
		if(vis[child])return true;
		isloop|=dfs(child,ver);
	}
	return isloop;
}


int main()
{
	int e,ver;
	cin>>ver>>e;

	for(int i=0;i<e;i++)
	{
		int a,b;
		cin>>a>>b;

		g[a].push_back(b);
		g[b].push_back(a);
	}

	// for connected components and cnt the below commented code and the commented dfs()

	// int cnt=0;

	// for(int i=1;i<=ver;i++)
	// {
	// 	if(vis[i])continue;
	// 	temp.clear();
	// 	dfs(i);
	// 	v.push_back(temp);
	// 	cnt++;
	// }
	// cout<<cnt;
	// for(auto &val:v)
	// {
	// 	for(auto &info:val)
	// 		cout<<info<<" ";
	// 	cout<<endl;
	// }

	//for cycle detection
	int flag=0;
	for(int i=1;i<=ver;i++)
	{
		if(vis[i])continue;
		if(dfs(i,0))
		{
			flag=1;
			break;
		}
	}

	if(flag)
		cout<<"Cycle exists";
	else
		cout<<"Cycle doesn't exists";

	return 0;
}