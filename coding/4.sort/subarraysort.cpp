#include<bits/stdc++.h>
using namespace std;

pair<int,int> subsort(vector<int> a,int n)
{
	int mx=-999,mn=999;

	for(int i=1;i<n-1;i++)
	{
		if((a[i]>a[i+1] && a[i]>a[i-1]) && a[i]>mx)
		{
			mx=a[i];
			
		}
		else if((a[i]<a[i+1] && a[i]<a[i-1]) && a[i]<mn)
			mn=a[i];
	}
	int i,j;
	cout<<mn<<" "<<mx<<endl;
	for(int k=0;k<n-1;k++)
	{
		if(mn<a[k])
		{
			i=k;
			break;
		}
	}

	for(int k=n-1;k>=0;k--)
	{
		if(a[k]<mx)
		{
			j=k;
			break;
		}
	}
	return make_pair(i,j);
}	

int main()
{
	int n;
	cin>>n;
	vector<int> a(n);

	for(int i=0;i<n;i++)
		cin>>a[i];
	pair<int,int> p=subsort(a,n);
	cout<<p.first<<" "<<p.second<<endl;
	return 0;
}