#include<bits/stdc++.h>
using namespace std;

vector<pair<string,string> > partition(vector<string> & v,int col)
{
	vector<pair<string,string> > p;

	for(auto &val:v)
	{
		int c=col-1;
		stringstream ss(val);
		string buffer;
		while(getline(ss,buffer,' ') && c)
		{
			c--;
		}
		p.push_back(make_pair(val,buffer));
	}
	return p;
}

int conv(string s)
{
	int p=1,ans=0;
	for(int i=s.size()-1;i>=0;i--)
	{
		ans+=(p*(s[i]-'0'));
		p*=10;
	}
	return ans;
}

bool num(pair<string,string> a,pair<string,string> b)
{
	return conv(a.second)<conv(b.second);
}

bool lex(pair<string,string> a,pair<string,string> b)
{
	return a.second<b.second;
}


int main()
{
	int n;
	cin>>n;
	cin.ignore();
	vector<string> v;
	for(int i=0;i<n;i++)
	{
		string str;
		getline(cin,str);
		v.push_back(str);
	}
	int col,numeric;
	cin>>col>>numeric;

	vector<pair<string,string> > p=partition(v,col);
	if(numeric)
		sort(p.begin(),p.end(),num);
	else
		sort(p.begin(),p.end(),lex);

	for(auto &val:p)
		cout<<val.first<<endl;
	
	return 0;

}