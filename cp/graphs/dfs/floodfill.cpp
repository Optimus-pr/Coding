#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > v;

void dfs(int i,int j,int m,int n)
{
	if(i<0 || j<0 ||i>=m||j>=n||v[i][j]!=1)
		return;
	v[i][j]=2;
	dfs(i+1,j,m,n);
	dfs(i,j+1,m,n);
	dfs(i-1,j,m,n);
	dfs(i,j-1,m,n);
}

int main()
{
	int m,n;
	cin>>m>>n;

	for(int i=0;i<m;i++)
	{
		vector<int> temp;
		for(int j=0;j<n;j++)
		{
			int ele;
			cin>>ele;
			temp.push_back(ele);
		}
		v.push_back(temp);
	}

	dfs(0,0,m,n);

	for(auto &val:v)
	{
		for(auto &info:val)
			cout<<info<<" ";
		cout<<endl;
	}
	return 0;
}