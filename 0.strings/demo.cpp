#include<bits/stdc++.h>
using namespace std;

int main()
{
	vector<string> v;
	for(int i=0;i<3;i++)
	{
		string s;
		getline(cin,s);
		v.push_back(s);

	}

	int cnt;
	vector<string> res;
	for(int i=0;i<3;i++)
	{
		cnt=2;
		stringstream ss(v[i]);
		string token;

		while(getline(ss,token,' ') && cnt)
		{
			cnt--;
		}
		res.push_back(token);
	}

	for(auto &val:res)
		cout<<val<<" ";
	cout<<endl;


}