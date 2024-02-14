#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;

	if(n==1)
	{
		cout<<"0";
		return 0;
	}
	bool flag=true;
	for(int i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			flag=false;break;
		}
	}
	cout<<flag;
	return 0;
}