#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,time;
	cin>>n>>time;

	int prod=n*time;

	int digit=log10(prod)+1;

	if(digit==1)
		cout<<n;
	else
	{
		int sum=0;
		while(prod)
		{
			sum+=prod%10;
			prod/=10;
		}
		cout<<sum%n;
	}
	return 0;
}