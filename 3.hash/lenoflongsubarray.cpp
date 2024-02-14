// to find the len of longest subarray with given sum

#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;
	vector<int> v(n);

	for(int i=0;i<n;i++)
		cin>>v[i];

	int size=0,sum=0;
	unordered_map<int,int> m;
	m[0]=-1;// bcause if k=0 and vector is 1 -1 0 trace

	for(int i=0;i<n;i++)
	{
		sum+=v[i];

		if(m.find(sum-k)!=m.end())
			size=max(size,i-m[sum-k]);
		
		if(m.find(sum)==m.end())
			m[sum]=i;
	}
	cout<<size<<endl;
	return 0;
}