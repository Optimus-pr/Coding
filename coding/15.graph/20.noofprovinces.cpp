#include<bits/stdc++.h>
using namespace std;

class disjoint{
	
public:
	vector<int> parent,size;

	disjoint(int n)
	{
		parent.resize(n);//to resize we can use this function
		size.resize(n,1);
		for(int i=0;i<n;i++)
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
		b=find(b);//these 2 lines are must 

		if(a!=b)
		{
			if(size[a]<size[b])
				swap(b,a);
			parent[b]=a;
			size[a]+=size[b];
		}
	}
};

int main()
{
	disjoint s(v);

	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		{
			if(adj[i][j]==1)
				s.Union(i,j);
		}
	}

	int cnt=0;
	for(int i=0;i<v;i++)
		if(s.parent[i]==i)
			cnt++;

	cout<<cnt;


}