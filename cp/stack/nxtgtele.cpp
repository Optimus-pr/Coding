#include<bits/stdc++.h>
using namespace std;

vector<int> compute(vector<int> &v)
{
	vector<int> q(v.size());
	stack<int> s;

	for(int i=0;i<v.size();i++)
	{
		while(!s.empty() && v[i]>v[s.top()])
		{
			q[s.top()]=v[i];
			s.pop();
		}
		s.push(i);
	}
	while(!s.empty())
	{
		q[s.top()]=-1;
		s.pop();
	}
	return q;
}

int main()
{
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++)
		cin>>v[i];
	vector<int> p=compute(v);

	for(auto &val:p)
		cout<<val<<" ";
	cout<<endl;
	return 0;
}