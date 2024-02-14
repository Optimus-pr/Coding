#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

int band(vector<int> &v)
{
	unordered_set<int> s;
	int cnt,mcnt;
	for(int i=0;i<v.size();i++)
		s.insert(v[i]);

	for(auto val:s)
	{
		cnt=1,mcnt=0;

		while(s.find(val-1)!=s.end())
			val--;
		int parent=val;
		
		while(s.find(parent)!=s.end())
		{
			parent++;
			cnt++;
		}
		mcnt=max(cnt,mcnt);
	}
	return mcnt;
}


int main()
{
	int n;
	cin>>n;
	vector<int> v(n);

	for(int i=0;i<n;i++)
		cin>>v[i];

	cout<<band(v);
}