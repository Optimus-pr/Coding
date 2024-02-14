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

int main()
{
	string s,temp="";
	cin>>s;

	compute(s,temp,0);

	for(auto &val:v)
		cout<<val<<endl;
	return 0;
}