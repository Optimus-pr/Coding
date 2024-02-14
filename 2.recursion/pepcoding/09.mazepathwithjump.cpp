#include<bits/stdc++.h>
using namespace std;

vector<string> printpath(int sr,int sc,int dr,int dc)
{

	if(dr==sr && sc==dc)
	{
		vector<string> v;
		v.push_back("");
		return v;
	}

	vector<string> right;
	vector<string> down;
	vector<string> diag;
	vector<string> ans;

	for(int i=1;i<=dc-sc;i++)
	{
		right=printpath(sr,sc+i,dr,dc);
		for(auto &val:right)
			ans.push_back("r"+char(i)+val);
	}

	for(int i=1;i<=dr-sr;i++)
	{
		right=printpath(sr+i,sc,dr,dc);
		for(auto &val:right)
			ans.push_back("d"+i+val);
	}

	for(int i=1;i<=dr-sr && i<=dc-sc;i++)
	{
		diag=printpath(sr+1,sc+1,dr,dc);
		for(auto &val:diag)
			ans.push_back("d"+i+val);
	}

	return ans;
}

int main()
{
	int m,n;
	cin>>m>>n;

	vector<string> v=printpath(0,0,m-1,n-1);
	for(auto &val:v)
		cout<<val<<" ";
	cout<<endl;
	cout<<v.size();

	return 0;
}