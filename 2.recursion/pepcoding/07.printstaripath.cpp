#include<bits/stdc++.h>
using namespace std;

vector<string> getpath(int n)
{
	if(n==0)
	{
		vector<string> ans;
		ans.push_back("");
		return ans;
	}
	else if(n<0)
	{
		vector<string> ans;
		return ans;
	}

	vector<string> p1=getpath(n-1);
	vector<string> p2=getpath(n-2);
	vector<string> p3=getpath(n-3);

	vector<string> res;

	for(auto &val:p1)
		res.push_back("1"+val);

	for(auto &val:p2)
		res.push_back("2"+val);

	for(auto &val:p3)
		res.push_back("3"+val);
	return res;
}

void printpath(int n,string t)
{
	if(n==0)
	{
		cout<<t;
		return;
	}
	else if(n<0)
		return;

	printpath(n-1,"1"+t);
	printpath(n-2,"2"+t);
	printpath(n-3,"3"+t);

}

int main()
{
	int n;
	cin>>n;
	vector<string> v=getpath(n);

	for(auto &val:v)
		cout<<val<<" ";
	cout<<endl;
}