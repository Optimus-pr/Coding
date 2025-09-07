#include<bits/stdc++.h>
using namespace std;

string compute(string s)
{
	deque<char> d;
	string res="";
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='/')
			continue;
		else if(s[i]=='.')
		{
			if(d.size()!=0 && s[i+1]=='.')
				d.pop_back();
			else
				continue;
		}
		else
			d.push_back(s[i]);
	}
	if(d.size()==0)
		res.push_back('/');
	while(d.size()!=0)
	{
		res.push_back('/');
		res.push_back(d.front());
		d.pop_front();
	}
	return res;
}

int main()
{
	string s;
	cin>>s;
	s=compute(s);
	cout<<s;
	return 0;

}