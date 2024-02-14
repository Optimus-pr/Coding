#include<bits/stdc++.h>
using namespace std;

void rec(string s,string t)
{
	if(s.size()==0)
	{
		cout<<t<<" ";
		return;
	}

	int one=stoi(s.substr(0,1));
	if(one==0)
		return;
	string rone=s.substr(1);
	rec(rone,t+char('a'+one-1));

	int two;

	if(s.size()>1)
	{
		two=stoi(s.substr(0,2));
		if(two>26)
			return;
		string rtwo=s.substr(2);
		rec(rtwo,t+char('a'+two-1));
	}
}

int main()
{
	string s;
	cin>>s;

	rec(s,"");
	return 0;
}