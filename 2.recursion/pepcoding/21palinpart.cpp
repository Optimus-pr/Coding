#include<bits/stdc++.h>
using namespace std;

bool ispalin(string s)
{
	int i=0,j=s.size()-1;

	while(i<j)
	{
		if(s[i]!=s[j])
			return false;
		i++;j--;
	}
	return true;
}

void palinpart(string a,string b)
{
	if(a.size()==0)
	{
		cout<<b<<endl;
		return;
	}

	string t="",ros="";
	for(int i=0;i<a.size();i++)
	{
		t=a.substr(0,i+1);
		ros=a.substr(i+1);
		if(ispalin(t))
			palinpart(ros,b+t+",");
		
	}

	return;
}

int main()
{
	string s;
	cin>>s;

	palinpart(s,"");
	return 0;
}