//note: no need to find min and all there will be atmost one element in rotated array such that a[j]>a[j+1] if there exists more than 1 in the sense false.
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++)
		cin>>v[i];

	int cnt=0;
	for(int j=0;j<n;j++)
	{
		if(v[j]>v[(j+1)%n])cnt++;
	}
	cout<<(cnt<=1);
	return 0;
}