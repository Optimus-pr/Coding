#include<bits/stdc++.h>
using namespace std;

int power(int a,int b)
{
	if(b==0)
		return 1;

	int t=power(a,b/2);
	int ans=t*t;
	if(b%2==1)
		ans*=a;
	return ans;
}	

int main()
{
	int a,b;
	cin>>a>>b;

	cout<<power(a,b);
	return 0;
}