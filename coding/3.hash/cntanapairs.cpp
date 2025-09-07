#include<bits/stdc++.h>
using namespace std;
vector<string> ans;

void substr(string &s,int i,int n,string &t)
{
	if(i==n)
	{
		ans.push_back(t);
		return;
	}

	t.push_back(s[i]);
	substr(s,i+1,n,t);
	t.pop_back();

	substr(s,i+1,n,t);
}

map<vector<int>,int> findanagram()
{
	map<vector<int>,int > m;
	for(auto &val:ans)
	{
		vector<int> v(26);
		for(int i=0;i<val.size();i++)
		{
			v[val[i]-'a']++;
		}
		m[v]++;
	}
	return m;
}

int main()
{
	string s;
	string t="";
	cin>>s;

	substr(s,0,s.size(),t);
	map<vector<int>,int> m=findanagram();
	
	// for(auto &val:m)
	// {
	// 	for(auto &info:val.first)
	// 		cout<<info<<" ";
	// 	cout<<"-";
	// 	cout<<val.second<<endl;
	// }

	int ans=0;
	for(auto &val:m)
	{
		if(val.second>1)
		{
			ans+=(val.second*(val.second-1))/2;
		}
	}
	
	cout<<ans;


	return 0;
}