#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

unordered_map<char,int> m={{'(',1},{'{',2},{'[',3},{')',-1},{'}',-2},{']',-3}};

int main()
{
	string s;
	cin>>s;
	stack<char> st;
	int flag=0;

	for(int i=0;i<st.size();i++)
	{
		if(m[s[i]]>0)
			st.push(s[i]);
		else
		{
			if(!st.empty() && m[s[i]]+m[st.top()]==0)
				st.pop();
			else
			{
				flag=1;break;
			}
		}
	}

	if(!st.empty())
		cout<<"No"<<endl;
	else if(flag)
		cout<<"No"<<endl;
	else
		cout<<"Yes"<<endl;
	return 0;

}