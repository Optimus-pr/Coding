//the aim is to find 3 closest number of the given number i.e 7 in this case we can even take that 3 in a variable and pass it also

#include<bits/stdc++.h>
using namespace std;

vector<int> kclose(int * a,int n,int k)
{
	vector<int> v;
	priority_queue<pair<int,int> > q;

	for(int i=0;i<n;i++)
	{
		q.push(make_pair(abs(k-a[i]),a[i]));

		if(q.size()>3)
			q.pop();
	}

	while(q.size())
	{
		pair<int,int> p=q.top();
		v.push_back(p.second);
		q.pop();
		
		
	}
	return v;
}

int main()
{
	int n,k;
	cin>>n;

	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];

	cin>>k;


	vector<int> v=kclose(a,n,k);

	for(auto &it:v)
		cout<<it<<" ";
	return 0;
}