//this is same as subseqsum where required sum is to be generated but here there can be more than 1 occurence of the given element

#include<bits/stdc++.h>
using namespace std;

void rec(int *a,vector<int> b,int n,int i,int sum)
{

	if(i==n)
	{
		if(sum==0)
		{
			for(auto &it:b)
				cout<<it<<" ";
			cout<<endl;
		}
		return; 
	}

	if(a[i]<=sum)//if we don't include this then it will be segmentation fault
	{
		b.push_back(a[i]);
		rec(a,b,n,i,sum-a[i]);
		b.pop_back();
	}


	rec(a,b,n,i+1,sum);
}

int main()
{
	int n,sum;
	cin>>n>>sum;

	int a[n];

	for(int i=0;i<n;i++)
		cin>>a[i];

	vector<int> b;

	rec(a,b,n,0,sum);
}