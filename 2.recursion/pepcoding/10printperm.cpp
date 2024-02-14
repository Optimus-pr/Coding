#include<bits/stdc++.h>
using namespace std;

void rec(string s,string f)
{
	if(s.size()==0)
	{
		cout<<f<<" ";
		return;
	}
	for(int i=0;i<s.size();i++)
	{
		char ch=s[i];
		string l=s.substr(0,i);
		string r=s.substr(i+1);
		rec(l+r,ch+f);
	}
}

int main()
{
	string s;
	cin>>s;

	rec(s,"");
	return 0;
}