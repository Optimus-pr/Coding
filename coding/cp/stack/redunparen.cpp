#include<bits/stdc++.h>
using namespace std;

bool compute(string s)
{
	stack<char> st;
	int flag;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]!=')')
			st.push(s[i]);
		else
		{
			flag=0;
			while(!st.empty() && st.top()!='(')
			{
				if(st.top()=='+'||st.top()=='-'||st.top()=='*'||st.top()=='/')
					flag=1;
				st.pop();
			}
			if(flag==0)
				return false;
			st.pop();
		}
	}
	return true;
}

int main()
{
	string s;
	cin>>s;

	cout<<compute(s);
	return 0;
}
