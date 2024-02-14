#include<bits/stdc++.h>
using namespace std;

int finddel(string s)
{
	stack<char> st;

	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='(')
			st.push('(');
		else if(s[i]==')')
		{
			if(!st.empty() && st.top()=='(')
				st.pop();
			else
				st.push(')');
		}
	}
	return st.size();
}

void rec(string s,int n)
{

	if(n==0)
	{
		if(finddel(s)==0)
			cout<<s<<endl;
		return;
	}

	for(int i=0;i<s.size();i++)
	{
		string lt=s.substr(0,i);
		string rt=s.substr(i+1);
		rec(lt+rt,n-1);
	}
}

int main()
{
	string s;
	cin>>s;

	int rd=finddel(s);

	rec(s,rd);

	return 0;
}