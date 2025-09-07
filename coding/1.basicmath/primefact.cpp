#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;

	vector<int> lp(n,0),hp(n,0),isprime(n,1);

	isprime[0]=isprime[1]=0;

	for(int i=2;i<=n;i++)
	{
		if(isprime[i])
		{
			lp[i]=hp[i]=i;
			for(int j=2*i;j<n;j+=i)
			{
				isprime[j]=false;
				hp[j]=i;
				if(lp[j]==0)
					lp[j]=i;
			}
		}
	}
	int cnt=0;
	while(n>1)
	{
		int pf=hp[n];
		while(n%pf==0)
		{
			cout<<pf<<" ";
			n/=pf;
		}
	}

	// for(int i=0;i<n;i++)
	// 	cout<<lp[i]<<" "<<hp[i]<<endl;
	return 0;
}