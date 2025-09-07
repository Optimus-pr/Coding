#include<bits/stdc++.h>
using namespace std;

vector<pair<string,int> > check(vector<pair<string,int> > & v,char c)
{
	vector<pair<string,int> > ans;
	for(auto &val:v)
	{
		string s=val.first;
		auto found = std::find(s.begin(), s.end(), c);

		if (found != s.end()) {
		    ans.push_back(val);
		} 
	}
	return ans;
}

int main()
{
	string s;
	char c;
	getline(cin,s);
	//cin.ignore();
	cin>>c;

	stringstream ss(s);
	string token;
	vector<string > v;
	
	while(getline(ss,token,' '))
	{
		v.push_back(token);
	}
	sort(v.begin(),v.end());

	
	
	vector<pair<string,int> > vv;
	int cnt=0;
	for(auto &val:v)
	{
		cnt++;
		vv.push_back(make_pair(val,cnt));
	}



	vector<pair<string,int> > ans=check(vv,c);
	for(auto &val:ans)
	{
		cout<<val.first<<" "<<val.second<<endl;
	}
	return 0;

}