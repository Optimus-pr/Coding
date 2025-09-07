

#include<bits/stdc++.h>
using namespace std;

int nearestpower(int n)
{
	int cnt=0;
	while((1<<cnt)<=n)cnt++;
	return cnt-1;
}

int rec(int n)
{
	if(n==0)
		return 0;

	int x=nearestpower(n);
	int t1=x*(1<<(x-1));//n*(2^n-1)
	int t2=n-(1<<x)+1;
	int val=n-(1<<x);
	return t1+t2+rec(val);

}

int main()
{
	int n;
	cin>>n;

	cout<<rec(n);
}