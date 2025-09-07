#include<bits/stdc++.h>
using namespace std;

void insrt(vector<int> &v,int tmp)
{
	if(v.size()==0 || v[v.size()-1]<=tmp)
	{
		v.push_back(tmp);
		return;
	}
	int end=v[v.size()-1];
	v.pop_back();
	insrt(v,tmp);
	v.push_back(end);
}


void srt(vector<int> &v)
{
	if(v.size()==0)
		return;
	int tmp=v[v.size()-1];
		v.pop_back();
	srt(v);

	insrt(v,tmp);
}

int main()
{
	int n;
	cin>>n;

	vector<int> v(n);

	for(int i=0;i<n;i++)
		cin>>v[i];

	srt(v);

	for(auto &it:v)
		cout<<it<<" ";
	cout<<endl;
}