#include<bits/stdc++.h>
using namespace std;

int main()
{
	queue<char> q;
	int n;
	cin>>n;

	vector<char> v(n);
	vector<char> ans;

	for(int i=0;i<n;i++)
		cin>>v[i];

	unordered_map<char,int> m;

	for(int i=0;i<n;i++)
	{
		if(++m[v[i]]==1)
			q.push(v[i]);
		if(q.size()==0)
			ans.push_back('0');
		else
		{
			while(q.size() && m[q.front()]>1)
				q.pop();
			if(q.size()==0)
				ans.push_back('0');
			else 
				ans.push_back(q.front());
		}
	}

	for(auto &val:ans)
		cout<<val<<" ";
	return 0;
}