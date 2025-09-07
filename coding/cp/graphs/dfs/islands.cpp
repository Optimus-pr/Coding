#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > v;

void dfs(int i,int j)
{
	if(i<0 || j<0 || i>=v.size()|| j>=v[0].size() || v[i][j]!=1)
		return;
	v[i][j]=2;
	dfs(i+1,j);
	dfs(i-1,j);
	dfs(i,j+1);
	dfs(i,j-1);

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

	int cnt=0;

	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(v[i][j]!=1)continue;
			dfs(i,j);
			cnt++;
		}
	}
	cout<<cnt<<endl;
	return 0;
}