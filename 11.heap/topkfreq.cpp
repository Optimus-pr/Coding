#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> p;

vector<int> topk(int *a,int n,int k)
{
	priority_queue<p,vector<p>,greater<p> > q;
	vector<int> v;
	unordered_map<int,int> u;

	for(int i=0;i<n;i++)
		u[a[i]]++;


	for(auto it:u)
	{
		q.push(make_pair(it.second,it.first));

		if(q.size()>k)
			q.pop();
	}

	while(!q.empty())
	{
		v.push_back(q.top().second);
		q.pop();
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

	vector<int> v=topk(a,n,k);

	for(auto &it:v)
		cout<<it<<" ";
	cout<<endl;
}