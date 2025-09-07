#include<bits/stdc++.h>
using namespace std;

void remdup(vector<int> &v)
{
	int i=0;
	while(i<v.size()-1)
	{
		if(v[i]==v[i+1])
			v.erase(v.begin()+i);
		else
			i++;
	}
}

int main()
{
	int n;
	cin>>n;

	vector<int> v(n);

	for(int i=0;i<n;i++)
		cin>>v[i];

	remdup(v);

	for(auto &val:v)
		cout<<val<<" ";
	return 0;
}