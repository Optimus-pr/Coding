#include<bits/stdc++.h>
using namespace std;

int main()
{
	int m,n;
	cin>>m>>n;

	int a[m],b[n];

	for(int i=0;i<m;i++)
		cin>>a[i];
	for(int j=0;j<n;j++)
		cin>>b[j];

	int i=0,j=0;
	vector<int> v;
	while(i<m && j<n)
	{
		if(a[i]<b[j])
			i++;
		else if(a[i]>b[j])
			j++;
		else
		{
			v.push_back(a[i]);
			i++;
			j++;
		}
	}

	for(auto &val:v)
		cout<<val<<" ";
	cout<<endl;
	return 0;
}