#include<bits/stdc++.h>
using namespace std;

vector<string> v;

void compute(string &s,string &temp,int i)
{
	if(i==s.size())
	{
		v.push_back(temp);
		return;
	}

	compute(s,temp,i+1);

	temp.push_back(s[i]);
	compute(s,temp,i+1);
	temp.pop_back();
}

bool cmp(string a,string b)
{
	if(a.size()==b.size())
		return a<b;
	else
		return a.size()<b.size();
}

int main()
{
	string s;
	cin>>s;
	string temp="";
	compute(s,temp,0);
	sort(v.begin(),v.end(),cmp);
	for(auto &val:v)
		cout<<val<<" ";
	return 0;
}