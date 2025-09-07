//here in this if there exists 2 ele with same freq then their order is not seen to fix it need to write comparator fn

#include<bits/stdc++.h>
using namespace std;

vector<int> topk(int *a,int n)
{
	priority_queue<pair<int,int> > q;
	vector<int> v;
	unordered_map<int,int> u;

	for(int i=0;i<n;i++)
		u[a[i]]++;


	for(auto it:u)
		q.push(make_pair(it.second,it.first));

	while(!q.empty())
	{	
		int cnt=q.top().first;
		while(cnt--)
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

	vector<int> v=topk(a,n);

	for(auto &it:v)
		cout<<it<<" ";
	cout<<endl;
}