//here we need to convert vector of int to string of numbers seperated by , and space

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<int> v(n);

	stringstream ss;
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
		ss<<v[i];
		if(i<n-1)
		{
			ss<<", ";
		}
	}
	string res=ss.str();
	cout<<res;
	return 0;
}	