//merging 2 sorted sub arrays in 0(1) time

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;

	vector<int> a(n),b(m);

	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<m;i++)
		cin>>b[i];
	int gap=ceil((n+m)/2.0);
	int i=0,j=gap-1;

	while(gap)
	{
		while(j<n+m)
		{
			if(i<n && j<n)
			{
				if(a[i]>a[j])
					swap(a[i],a[j]);
				i++;j++;
			}
			else if(i<n)
			{
				if(a[i]>b[j%n])
					swap(a[i],b[j%n]);
				i++;j++;
			}
			else if(i>=n && j>=n)
			{
				if(a[i%n]>b[j%n])
					swap(a[i%n],b[j%n]);
				i++;j++;
			}
		}
		gap/=2;
		i=0,j=gap;
	}

	for(auto &val:a)
		cout<<val<<" ";
	for(auto &val:b)
		cout<<val<<" ";
	return 0;

}