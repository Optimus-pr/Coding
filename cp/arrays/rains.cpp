#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
int l[N];
int r[N];

int rain(vector<int> &v)
{
	int sum=0;
	for(int i=0;i<v.size();i++)
	{
		sum+=(min(r[i],l[i])-v[i]);
	}
	return sum;
}

int main()
{
	int n;
	cin>>n;

	vector<int> v(n);

	for(int i=0;i<n;i++)
		cin>>v[i];
	int max=v[0];
	l[0]=max;
	for(int i=1;i<n;i++)
	{
		if(v[i]>max)
			max=v[i];
		l[i]=max;
	}

	max=v[v.size()-1];
	r[v.size()-1]=max;
	for(int i=v.size()-2;i>=0;i--)
	{
		if(v[i]>max)
			max=v[i];
		r[i]=max;
	}

	cout<<rain(v);

	return 0;


}