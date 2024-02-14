#include<bits/stdc++.h>
using namespace std;

vector<string> fizz(int n)
{
	vector<string> s;
	for(int i=0;i<n;i++)
	{
		if(i%15==0)
			s.push_back("fizzbuzz");
		else if(i%3==0)
			s.push_back("fizz");
		else if(i%5==0)
			s.push_back("buzz");
		else
			s.push_back(to_string(i));
	}
	return s;
}

int main()
{
	int n;
	cin>>n;

	vector<string> s=fizz(n);

	for(auto &val:s)
		cout<<val<<" ";
	cout<<endl;
	return 0;
}