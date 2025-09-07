// 0(n!) time and 0(n) space in perm2 we are going to get rid of 0(n) space,

#include<bits/stdc++.h>
using namespace std;

void rec(int *a,int *f,vector<int> &v,int n)
{

	if(v.size()==n)
	{
		for(auto it:v)
			cout<<it<<" ";
		cout<<endl;
		return;
	}

	for(int i=0;i<n;i++)
	{
		if(!f[i])
		{
			v.push_back(a[i]);
			f[i]=1;
			rec(a,f,v,n);
			f[i]=0;
			v.pop_back();
		}
	}
}

int main()
{
	int n;
	cin>>n;

	int a[n],f[n];
	vector<int> v;

	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		f[i]=0;
	}

	rec(a,f,v,n);
}