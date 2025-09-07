#include<bits/stdc++.h>
using namespace std;
int main()
{
	vector<vector<int> > v(3,vector<int> (3));
	// 1 2 3 4 5 6 7 8 9

	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			cin>>v[i][j];

	int i=0,j=0,r=3,c=3;
	for(int k=0;k<c;k++)
	{
		if(k%2==0)
			for(int a=0;a<r;a++)
				cout<<v[a][k]<<" ";
		else
			for(int a=r-1;a>=0;a--)
				cout<<v[a][k]<<" ";
		cout<<endl;
	}

	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
			cout<<v[i][j]<<" ";
		cout<<endl;
	}
}