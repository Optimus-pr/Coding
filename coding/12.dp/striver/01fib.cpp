#include<bits/stdc++.h>
using namespace std;

int fib(int n)
{
	
	int p=0,c=1,fib;
	for(int i=2;i<=n;i++)
	{
		fib=c+p;
		p=c;
		c=fib;
	}
	return c;

}

int main()
{
	int n;
	cin>>n;
	
	cout<<fib(n);
	return 0;
}