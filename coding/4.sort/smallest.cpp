#include<bits/stdc++.h>
using namespace std;

bool cmp(string a,string b)
{
	string c=a+b;
	string d=b+a;
	if(c>d)
		return true;
	return false;
}

int main()
{
	int n;
	cin>>n;
	vector<string> v(n);
	

	for(int i=0;i<n;i++)
		cin>>v[i];

	sort(v.begin(),v.end(),cmp);

	for(auto &val:v)
		cout<<val<<" ";
	return 0;
}