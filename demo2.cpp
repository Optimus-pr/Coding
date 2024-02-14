#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,w;
	cin>>n>>w;
	vector<int> v(n);

	for(int i=0;i<n;i++)
	{
		cin>>v[i];
		sum+=v[i];
	}
	sort(v.begin(),v.end());

	if(sum<w)
		cout<<"0";
	else
	{
		while(sum<=w)
		{
			if(v[n-1]!=v[0])
			{
				v[n-1]=v[0];
				sum-=(v[n-1]-v[0]);
				
			}
			else
			{
				v[n-1]--;
			}
			cnt++;
			sort(v.begin(),v.end());
		}
	}
	cout<<cnt;
	return 0;
}