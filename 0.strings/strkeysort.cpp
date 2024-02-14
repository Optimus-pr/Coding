#include<bits/stdc++.h>
using namespace std;

bool lex(pair<string,string> &a,pair<string,string> &b)
{
	return a.first<b.first;
}

bool num(pair<string,string> &a,pair<string,string> &b)
{
	return stoi(a.first)<stoi(b.first);
}

int main()
{
	int n,key,t,order;
	cin>>n>>key>>order;

	cin.ignore();
	vector<pair<string,string> > res;
	for(int i=0;i<n;i++)
	{
		string s;
		getline(cin,s);

		stringstream ss(s);
		t=key-1;
		string token;
		while(getline(ss,token,' ') && t--){}
		res.push_back(make_pair(token,s));
	}

	if(order==1)
		sort(res.begin(),res.end(),lex);
	else
		sort(res.begin(),res.end(),num);
	cout<<endl;
	for(auto &val:res)
		cout<<val.second<<endl;
}