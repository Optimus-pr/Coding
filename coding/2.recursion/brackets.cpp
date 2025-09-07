#include<bits/stdc++.h>
using namespace std;

void rec(vector<char> &v,int open,int close)
{
	if(open==0 && close==0)
	{
		for(auto &val:v)
			cout<<val;
		cout<<endl;
		return;
	}

	if(open>0)
	{
		v.push_back('(');
		rec(v,open-1,close);
		v.pop_back();
	}

	//no need to add extra condition i.e if(close>0)
	if(open<close)
	{
		v.push_back(')');
		rec(v,open,close-1);
		v.pop_back();
	}
	
}

int main()
{
	int n;
	cin>>n;
	vector<char> v;
	rec(v,n,n);
	return 0;
}