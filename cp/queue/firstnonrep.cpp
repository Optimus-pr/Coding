#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

vector<char> compute(string s)
{
	queue<char> q;
	unordered_map<char,int> m;
	vector<char> v;
	for(int i=0;i<s.size();i++)
	{	
		m[s[i]]++;
		if(m[s[i]]==1)
			q.push(s[i]);
		while(!q.empty() && m[q.front()]!=1)
			q.pop();
		if(!q.empty())
		v.push_back(q.front());
	else
		v.push_back('1');
	}
	return v;
}

int main()
{
	string s;
	cin>>s;
	auto v=compute(s);
	for(auto &val:v)
		cout<<val<<" ";
	cout<<endl;
	return 0;
}