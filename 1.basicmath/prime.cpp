#include<bits/stdc++.h>
using namespace std;
const int N=1e3;

vector<int> isprime(N,1);


int main()
{
	int n;
	cin>>n;

	isprime[0]=isprime[1]=0;

	for(int i=2;i*i<=n;i++)
	{
		if(isprime[i])
		{
			for(int j=i*i;j<=n;j+=i)//j=2*i also works
				isprime[j]=false;
		}
	}
	
	for(int i=0;i<n;i++)
		cout<<i<<" "<<isprime[i]<<endl;
	return 0;
}