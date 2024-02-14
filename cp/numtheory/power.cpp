#include<bits/stdc++.h>
using namespace std;

int rec_power(int a,int b)
{
	if(b==0)
		return 1;
	int res=rec_power(a,b/2);
	if(b&1)
		return a*res*res;
	else
		return res*res;
}

int power(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b&1)
			ans*=a;
		a*=a;
		b>>=1;
	}
	return ans;
}

int main()
{
	int a,b;
	cin>>a>>b;

	cout<<power(a,b);
	return 0;
}