#include<bits/stdc++.h>
using namespace std;

int gcd(int m,int n)
{
	if(n==0)return m;
	return gcd(n,m%n);
}

int main()
{
	int a,b;
	cin>>a>>b;
	int g=gcd(a,b);
	cout<<"Gcd of "<<a<<" And "<<b<<" is: "<<g<<endl;
	cout<<"Lcm of "<<a<<" And "<<b<<" is: "<<(a*b)/g;
	return 0;
}