#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

int minswap(vector<int> a,vector<int> b,int n)
{
	unordered_map<int,int> m;
	unordered_set<int> vis,temp;

	int cnt=0;

	for(int i=0;i<n;i++)
		m.insert(make_pair(b[i],i));

	for(int i=0;i<n;i++)
	{
		if(vis.find(a[i])==vis.end() && m[a[i]]!=i)
		{
			vis.insert(a[i]);
			temp.insert(a[i]);
			int ele=a[m[a[i]]];
			while(temp.find(ele)==temp.end())
			{
				vis.insert(ele);
				temp.insert(ele);
				ele=a[m[ele]];
			}
			cnt+=(temp.size()-1);
			temp.clear();
		}
		else if(m[a[i]]==i)
			vis.insert(a[i]);
	}
	return cnt;
}

int main()
{
	int n;
	cin>>n;

	vector<int> a(n),b(n);

	for(int i=0;i<n;i++)
		cin>>a[i];
	b=a;
	sort(b.begin(),b.end());

	cout<<minswap(a,b,n);
	return 0;
}