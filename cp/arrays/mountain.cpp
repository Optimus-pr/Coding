#include<bits/stdc++.h>
using namespace std;

int mountain(vector<int> &v)
{
	int cnt=1,mcnt=1;
	for(int i=1;i<v.size()-1;i++)
	{
		if(v[i]>v[i+1] && v[i]>v[i-1])
		{
			int j=i;
			cnt=1;
			while(j>0 && v[j]>v[j-1])
			{
				j--;
				cnt++;
			}
			while(v[i]>v[i+1] && i<v.size()-1)
			{
				i++;
				cnt++;
			}
		}
		mcnt=max(cnt,mcnt);
	}
	return mcnt;
}

int main()
{
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++)
		cin>>v[i];

	cout<<mountain(v);
	return 0;
}