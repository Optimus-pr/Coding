#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;

	vector<int> v(n);

	for(int i=0;i<n;i++)
		cin>>v[i];

	sort(v.begin(),v.end());

	bool res=binary_search(v.begin(),v.end(),5);

	cout<<res;
	return 0;
}