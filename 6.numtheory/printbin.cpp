#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;

	for(int i=12;i>=0;i--)
	{
		if((n>>i)&1)
			cout<<"1";
		else
			cout<<"0";
	}
	return 0;
}
