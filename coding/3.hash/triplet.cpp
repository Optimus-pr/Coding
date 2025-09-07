//count triplets in gp given r such that i<j<k

#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

int triplet(int *a,int n,int r)
{
	unordered_map<int,int> lt,rt;

	for(int i=0;i<n;i++)
	{
		lt[a[i]]=0;
		rt[a[i]]++;
	}

	int ans=0;

	for(int i=0;i<n;i++)
	{
		rt[a[i]]--;

		if(a[i]%r==0)//since this is only for int
		{
			int m=a[i]/r;
			int o=a[i]*r;

			ans+=lt[m]*rt[o];
		}

		lt[a[i]]++;
	}
	return ans;
}

int main()
{
	int n,r;
	cin>>n>>r;

	int a[n];

	for(int i=0;i<n;i++)
		cin>>a[i];

	cout<<triplet(a,n,r);
}