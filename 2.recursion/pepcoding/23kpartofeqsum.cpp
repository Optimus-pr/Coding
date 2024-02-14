#include<bits/stdc++.h>
using namespace std;

void rec(vector<vector<int> > v,vector<int> s,int *a,int id,int sid,int k,int n)
{

	if(id==n)
	{
		if(sid==k)
		{
			bool flag=true;
	
			for(int i=0;i<k-1;i++)
				if(s[i]!=s[i+1])
				{
					flag=false;
					break;
				}

			if(flag)
			{clear
		
				for(auto &val:v)
				{
					for(auto &info:val)
					{
						cout<<info<<" ";
					}
					cout<<endl;
				}
			}
		}
		return;
	}
	

	for(int i=0;i<k;i++)
	{
		if(v[i].size()>0)
		{
			v[i].push_back(a[id]);
			s[i]+=a[id];
			rec(v,s,a,id+1,sid,k,n);
			v[i].pop_back();
			s[i]-=a[id];
		}
		else
		{
			v[i].push_back(a[id]);
			s[i]+=a[id];
			rec(v,s,a,id+1,sid+1,k,n);
			v[i].pop_back();
			s[i]-=a[id];
			break;
		}
	}
}

int main()
{
	int n,k,sum=0;
	cin>>n>>k;//if k>n then we can't make k eql partition of n

	int a[n];

	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}

	if(sum%k!=0)
		return 0;

	vector<vector<int> > v(k,vector<int>());
	vector<int> s(k,0);

	rec(v,s,a,0,0,k,n);
	return 0;
}