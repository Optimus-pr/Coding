#include<bits/stdc++.h>
using namespace std;

int rec(int n,int k)
{
	if(n==0)
		return 0;
	
	int x=rec(n-1,k);
	int y=(x+k)%n;

	return y;
}

int main()
{
	int n,k;
	cin>>n>>k;

	cout<<rec(n,k);
	return 0;
}