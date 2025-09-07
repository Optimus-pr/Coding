#include<bits/stdc++.h>
using namespace std;

void getsubseq(string s,string t,int n)
{
	if(s.size()==0)
	{
		if(n==0)
			cout<<t<<" ";
		else
			cout<<t+to_string(n)<<" ";
		return;
	}

	char ch=s[0];
	string rs=s.substr(1);

	getsubseq(rs,t+"",n+1);

	if(n)
		getsubseq(rs,t+to_string(n)+ch,0);
	else
		getsubseq(rs,t+ch,0);
}

int main()
{
	string s;
	cin>>s;

	getsubseq(s,"",0);
	return 0;
}