#include<bits/stdc++.h>
using namespace std;


void rec(vector<int> &v,int *a,int i,int n)
{

	for(auto & val:v)
		cout<<val<<" ";
	cout<<endl;

	for(int j=i;j<n;j++)
	{
		if(j>i && a[j]==a[j-1])continue;		
		v.push_back(a[j]);
		rec(v,a,j+1,n);
		v.pop_back();
	}
}

int main()
{
	int n;
	cin>>n;

	int a[n];


	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);

	vector<int> v;

	rec(v,a,0,n);


	return 0;
}