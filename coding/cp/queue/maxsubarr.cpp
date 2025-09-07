#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;
	vector<int> v(n);

	for(int i=0;i<n;i++)
		cin>>v[i];

	// for(int i=0;i<=n-k;i++)
	// {
	// 	cout<<*max_element(v.begin()+i,v.begin()+i+k);
	// }

	deque<int> d;
	int max=-999;
	for(int i=0;i<n;)
	{
		while(d.size()!=k)
		{
			d.push_back(v[i]);
			if(v[i]>max)
				max=v[i];
			i++;
		}
		
		cout<<max<<" ";
		d.pop_front();
		
	}
	return 0;
}