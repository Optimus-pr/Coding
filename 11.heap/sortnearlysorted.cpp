#include<bits/stdc++.h>
using namespace std;

vector<int> srt(int *a,int n,int k)
{
	priority_queue<int,vector<int>,greater<int> > minh;

	vector<int> v;

	for(int i=0;i<n;i++)
	{
		minh.push(a[i]);

		if(minh.size()>k)
		{
			v.push_back(minh.top());
			minh.pop();
		}
	}

	while(minh.size()){
		v.push_back(minh.top());
		minh.pop();
	}

	return v;
}

int main()
{
	int n;
	cin>>n;

	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];

	int k;
	cin>>k;



	vector<int> v=srt(a,n,k);

	for(auto it:v)
		cout<<it<<" ";
}