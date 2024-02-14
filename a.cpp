#include<bits/stdc++.h>
using namespace std;

int main()
{
	unordered_map<int,int> m;

	int n,k;
	cin>>n>>k;

	vector<int> v(n);

	for(int i=0;i<n;i++)
		cin>>v[i];

	int i=0,j=0,cnt=0;

	while(j<n)
	{
		m[v[j]]++;

		if(j-i+1<k)
			j++;
		else if(j-i+1==k)
		{
			for(auto &val:m)
				if(val.second==1)
					cnt++;

			if((--m[v[i]])==0)
				m.erase(v[i]);
			i++;
			j++;
		}

	}
	cout<<cnt;
	return 0;
}