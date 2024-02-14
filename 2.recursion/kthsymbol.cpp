/*
  1 2 3 4 5 6 7 8
1.0				  ->2^0 elements
2.0 1			  ->2^1 ele
3.0 1 1 0
4.0 1 1 0 1 0 0 1
*/

#include<bits/stdc++.h>
using namespace std;

int power(int a,int b)
{
	int ans=1,p=1;
	while(b)
	{
		if(b&1)
			ans*=a;
		a*=a;
		b>>=1;
	}
	return ans;
}

int rec(int n,int k)
{
	cout<<n<<" "<<k<<endl;

	if(n==1 && k==1)
		return 0;

	int mid=(power(2,n-1))/2;

	if(k<=mid)
		return rec(n-1,k);
	else
		return !rec(n-1,k-mid);
}

int main()
{
	int n,k;
	cin>>n>>k;

	cout<<rec(n,k);
	return 0;
}