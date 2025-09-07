#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

void compute(vector<int> &v,int ts)
{
	unordered_set<int> u;
	for(int i=0;i<v.size();i++)
	{
		if(u.find(ts-v[i])==u.end())
			u.insert(v[i]);
		else
			cout<<v[i]<<" "<<ts-v[i]<<endl;
	}
}

int main()
{
	int n,ts;
	cin>>n>>ts;
	vector<int> v(n);

	for(int i=0;i<n;i++)
		cin>>v[i];

	compute(v,ts);
	return 0;
}