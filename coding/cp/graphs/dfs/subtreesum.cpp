#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
vector<int> g[N];
int sub[N];

void dfs(int v,int p=-1)
{
	sub[v]+=v;
	for(auto child:g[v])
	{
		if(child==p)continue;
		dfs(child,v);
		sub[v]+=sub[child];
	}
}

int main()
{
	int v;
	cin>>v;

	for(int i=0;i<v-1;i++)
	{
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(1);
	for(int i=1;i<=v;i++)
		cout<<i<<" "<<sub[i]<<endl;
	return 0;

}