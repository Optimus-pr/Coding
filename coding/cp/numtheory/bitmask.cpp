#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a[]={1,2,3};
	int b[]={2,3};

	int p1=0,p2=0;
	for(int i=0;i<3;i++)
		p1|=(1<<a[i]);

	for(int j=0;j<2;j++)
		p2|=(1<<b[j]);

	int ans=p1&p2;

	for(int i=0;i<4;i++)
	{
		if((ans&(1<<i))!=0)
			cout<<i<<" ";
	}
	return 0;
}