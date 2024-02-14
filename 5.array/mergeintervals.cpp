#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;

	vector<vector<int> > v;

	for(int i=0;i<n;i++)
	{
		vector<int> t;
		int a,b;
		cin>>a>>b;
		t.push_back(a);
		t.push_back(b);
		v.push_back(t);
	}

	vector<vector<int> > ans;
	
	sort(v.begin(),v.end());
	for(int i=0;i<n;i++)
	{
		if(ans.size()==0 || v[i][0]>ans.back()[1])
			ans.push_back(v[i]);
		else
			ans.back()[1]=max(ans.back()[1],v[i][1]);
	}



	return 0;
}