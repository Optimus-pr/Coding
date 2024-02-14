#include<bits/stdc++.h>
using namespace std;

int getnum(string s,unordered_map<char,int> m)
{
	int sum=0;
	for(int i=0;i<s.size();i++)
		sum=sum*10+m[s[i]];
	
	return sum;
}


void solution(string s1,string s2,string s3,string t,unordered_map<char,int> m,unordered_map<int,int> n,int id)
{
	if(id==t.size())
	{
		int a=getnum(s1,m);
		int b=getnum(s2,m);
		int c=getnum(s3,m);

		if(a+b==c)
		{
			for(auto &val:m)
				cout<<val.first<<"-"<<val.second<<",";
			cout<<endl;
		}
		return;
	}
	
	for(int i=0;i<=9;i++)
	{
		if(n[i]==0)
		{
			m[t[id]]=i;
			n[i]=1;
			solution(s1,s2,s3,t,m,n,id+1);
			m[t[id]]=-1;
			n[i]=0;
		}
	}
}

int main()
{
	string s1,s2,s3;
	cin>>s1>>s2>>s3;

	unordered_map<char,int> s;
	unordered_map<int,int> n;

	for(int i=0;i<=9;i++)
		n.insert(make_pair(i,0));

	string t="";

	for(int i=0;i<s1.size();i++)
		if(s.find(s1[i])==s.end())
		{
			t+=s1[i];
			s.insert(make_pair(s1[i],-1));
		}

	for(int i=0;i<s2.size();i++)
		if(s.find(s2[i])==s.end())
		{
			t+=s2[i];
			s.insert(make_pair(s2[i],-1));
		}

	for(int i=0;i<s3.size();i++)
		if(s.find(s3[i])==s.end())
		{
			t+=s3[i];
			s.insert(make_pair(s3[i],-1));
		}

	solution(s1,s2,s3,t,s,n,0);

	return 0;
}