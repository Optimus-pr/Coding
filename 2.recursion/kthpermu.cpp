#include<bits/stdc++.h>
using namespace std;

string kthper(int n,int k)
{
	int fact=1;
	vector<int> v;

	for(int i=1;i<n;i++)
	{
		fact*=i;
		v.push_back(i);
	}
	v.push_back(n);
	k=k-1;
	string str="";
	while(true)
	{
		str=str + to_string(v[k/fact]);
		v.erase(v.begin()+(k/fact));

		if(v.size()==0)
			break;

		k=k%fact;
		fact=fact/v.size();
	}
	return str;
	
}

int main()
{
	int n,k;
	cin>>n>>k;

	cout<<kthper(n,k);
}