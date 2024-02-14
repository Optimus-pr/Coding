#include<bits/stdc++.h>
using namespace std;

vector<string> st={".:","abc","def","ghi","jkl","mno","pqrs","tu","vwx","yz"};

vector<string> getkeycombi(string s)
{
	if(s.size()==0)
	{
		vector<string> ans;
		ans.push_back("");
		return ans ;
	}

	int ch=s[0]-'0';
	string rs=s.substr(1);
	vector<string> v=getkeycombi(rs);
	vector<string> res;

	for(int i=0;i<st[ch].size();i++)
	{
		for(int j=0;j<v.size();j++)
			res.push_back(st[ch][i]+v[j]);
			
	}

	return res;
}

void printkeycombi(string s,string t)
{
	if(s.size()==0)
	{
		cout<<t<<" ";
		return ; 
	}

	int ch=s[0]-'0';
	string rs=s.substr(1);
	for(int i=0;i<st[ch].size();i++)
		printkeycombi(rs,st[ch][i]+t);
}

int main()
{
	string s;
	cin>>s;

	// vector<string> v=getkeycombi(s);

	// for(auto &val:v)
	// 	cout<<val<<" ";
	// cout<<endl;
	printkeycombi(s,"");
	
	return 0;
}