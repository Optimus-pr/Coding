#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

void rec(string a,string b,unordered_set<string> s)
{
	if(a.size()==0)
	{
		cout<<b<<endl;
		return;
	}

	for(int i=0;i<a.size();i++)
	{
		string t=a.substr(0,i+1);
		string ros=a.substr(i+1);

		if(s.find(t)!=s.end())
			rec(ros,b+t+",",s);
	}
}

int main()
{
	int n;
	cin>>n;

	string s;
	unordered_set<string> m;

	for(int i=0;i<n;i++)
	{
		cin>>s;
		m.insert(s);
	}
	cin>>s;

	rec(s,"",m);
	return 0;

}