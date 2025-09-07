#include<bits/stdc++.h>
using namespace std;
	

vector<pair<int,vector<int> > > res;


void rec(vector<int> &v,int n,int i,vector<int> &temp,int sum)
{

	if(i==n)
	{
		res.push_back(make_pair(sum,temp));
		return;
	}

	temp.push_back(v[i]);
	rec(v,n,i+1,temp,sum+v[i]);
	temp.pop_back();

	rec(v,n,i+1,temp,sum);
}

bool cmp(pair<int,vector<int> > a,pair<int,vector<int> > b)
{
	if(a.second.size()!=b.second.size())
		return a.second.size()<b.second.size();
	else
		return a.second<b.second;
}

int main()
{
	int n;
	cin>>n;

	vector<int> v(n);
	vector<int> temp;

	for(int i=0;i<n;i++)
		cin>>v[i];

	rec(v,n,0,temp,0);

	sort(res.begin(),res.end(),cmp);

	for(auto &it:res)
	{
		cout<<it.first<<"    ";
		for(auto val:it.second)
			cout<<val<<" ";
		cout<<endl;
	}
}