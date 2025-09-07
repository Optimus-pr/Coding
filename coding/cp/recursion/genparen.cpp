#include<bits/stdc++.h>
using namespace std;

vector<string> v;

void compute(string &s,int open,int close)
{

	if(open==0 && close==0)
	{
		v.push_back(s);
		return;
	}

	if(open>0)
	{
		s.push_back('(');
		compute(s,open-1,close);
		s.pop_back();
	}

	if(close>open && close>0)
	{
		s.push_back(')');
		compute(s,open,close-1);
		s.pop_back();
	}

}

int main()
{
	int n;
	cin>>n;
	string s="";
	compute(s,n,n);

	for(auto & val:v)
		cout<<val<<endl;
	return 0;
}