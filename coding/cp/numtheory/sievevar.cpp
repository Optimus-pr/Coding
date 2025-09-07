#include<bits/stdc++.h>
using namespace std;

vector<bool> is_prime(30,1);
vector<int> lp(30,0),hp(30,0);

int main()
{
	vector<int> p;
	is_prime[0]=is_prime[1]=0;
	for(int i=2;i*i<=30;i++)
	{
		if(is_prime[i]==true)
		{
			hp[i]=lp[i]=i;
			for(int j=2*i;j<=30;j+=i)
			{
				is_prime[j]=false;
				hp[j]=i;
				if(lp[j]==0)
					lp[j]=i;
			}
		}
	}
	int n;
	cin>>n;

	while(n>1)
	{
		int pf=hp[n];
		while(n%pf==0)
		{
			p.push_back(pf);
			n/=pf;
		}
	}

	for(auto &val:p)
		cout<<val<<" ";

	// for(int i=2;i<=30;i++)
	// 	cout<<hp[i]<<" "<<lp[i]<<endl;
	return 0;
}