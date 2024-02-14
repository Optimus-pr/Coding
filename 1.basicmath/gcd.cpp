#include<bits/stdc++.h>
using namespace std;

//O(logɸmin(a,b)),where ɸ is 1.61.
// int gcd(int a,int b)
// {
// 	if(b==0)
// 		return a;
// 	return gcd(b,a%b);
// }

int main()
{
	int a,b;
	cin>>a>>b;

	// cout<<gcd(a,b);
	// cout<<a*b/gcd(a,b);//lcm;

	int gcd=1;
	for(int i=min(a,b);i>=2;i--)
	{
		if(a%i==0 && b%i==0)
		{
			gcd=i;
			break;
		}
	}
	cout<<gcd;
	return 0;
}