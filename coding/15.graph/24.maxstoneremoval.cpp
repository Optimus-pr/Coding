#include<bits/stdc++.h>
using namespace std;

class dsu
{
public:
	vector<int> p,s;

	dsu(int n)
	{
		parent.resize(n+1);
		size.resize(n+1,1);

		for(int i=0;i<=n;i++)
			parent[i]=i;
	}

	int find(int i)
	{
		if(parent[i]==i)
			return i;
		return parent[i]=find(parent[i]);
	}

	void Union(int a,int b)
	{
		a=find(a);
		b=find(b);

		if(find(a)!=find(b))
		{
			if(size[a]<size[b])
				swap(a,b);
			parent[b]=a;
			size[a]+=size[b];
		}
	}
}

int main()
{
	vector<vector<int> > v;
	int 
}