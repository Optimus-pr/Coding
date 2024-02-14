#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
vector<int> g[N];
int dp[N];

void dfs(int v,int p=-1)
{
	for(auto child:g[v])
	{
		if(child==p)continue;
		dp[child]=dp[v]+1;
		dfs(child,v);
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
	int max=-999,maxi=1;
	for(int i=1;i<=v;i++)
	{
		if(max<dp[i])
		{
			max=dp[i];
			maxi=i;
		}
		dp[i]=0;
	}
	dfs(maxi);

	max=*max_element(dp,dp+N);
	cout<<max<<endl;
	return 0;

}