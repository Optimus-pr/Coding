//longest common subsequence

#include<bits/stdc++.h>
#include<unordered_set>	
using namespace std;

int main()
{
	int n,li,hi;
	cin>>n;

	int a[n];
	unordered_set<int> u;

	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		u.insert(a[i]);
	}

	int i=0,cnt=-999,mcnt=-999;
	while(i<n)
	{
		if(u.find(a[i]-1)!=u.end())i++;
		else
		{
			cnt=0;
			int t=a[i];
			while(u.find(t)!=u.end())
			{
				cnt++;
				t++;
			}
			if(cnt>mcnt)
			{
				li=a[i];
				hi=t-1;
				mcnt=cnt;
			}
			i++;
		}
	}

	for(i=1;i<=mcnt;i++)
		cout<<li++<<" ";
	cout<<endl;
	return 0;

}