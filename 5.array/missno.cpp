#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int sum=0;
	vector<int> v(n);

	for(int i=0;i<n-1;i++)
	{
		cin>>v[i];
		sum+=v[i];
	}
	int exp=n*(n+1)/2;
	cout<<exp-sum;
	return 0;

}