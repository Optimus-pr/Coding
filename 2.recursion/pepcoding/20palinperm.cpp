#include<bits/stdc++.h>
using namespace std;

void solution(int st,int e,unordered_map<char,int> m,char c,string s)
{
	if(st>e)
	{
		string rev="";
		for(int i=s.size()-1;i>=0;i--)
			rev+=s[i];

		if(c!=NULL)
			cout<<s+c+rev<<endl;
		else
			cout<<s+rev<<endl;
		return;
	}

	for(auto &val:m)
	{
		if(val.second>0)
		{
			int cnt=val.second;
			m[val.first]=cnt-1;
			solution(st+1,e,m,c,val.first+s);
			m[val.first]=cnt+1;
		}
	}
}

int main()
{
	string s;
	cin>>s;

	unordered_map<char,int> m;

	for(auto &ch:s)
		m[ch]++;

	int ocnt=0,freq=0;
	char ochar=NULL;

	for(auto &val:m)
	{
		if(val.second%2==1)
		{
			ocnt++;
			ochar=val.first;
		}
		freq+=val.second/2;
		m[val.first]=val.second/2;
	}

	if(ocnt>1)
		return 0;

	solution(1,freq,m,ochar,"");

	return 0;
}