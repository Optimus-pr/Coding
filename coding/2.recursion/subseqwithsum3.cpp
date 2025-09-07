#include<bits/stdc++.h>
using namespace std;

void rec(int *a,vector<int> v,int sum,int n,int i)
{
	if(sum==0)
	{
		for(auto &it:v)
			cout<<it<<" ";
		cout<<endl;
	return;
	}

	for(int j=i;j<n;j++)
	{
		if(j>i && a[j]==a[j-1])
			continue;
		if(a[j]>sum)break;
		v.push_back(a[j]);
		rec(a,v,sum-a[j],n,j+1);
		v.pop_back();
	}
}

int main()
{
	int n,sum;
	cin>>n>>sum;

	int a[n];

	for(int i=0;i<n;i++)
		cin>>a[i];

	vector<int> v;

	rec(a,v,sum,n,0);

}