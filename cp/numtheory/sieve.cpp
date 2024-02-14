#include<bits/stdc++.h>
using namespace std;
vector<bool> is_prime(30,1);

int main()
{
	is_prime[0]=is_prime[1]=false;

	for(int i=2;i*i<=30;i++)
	{
		if(is_prime[i])
		{
			for(int j=i*i;j<=100;j+=i)//here we can also place j=2*i but i*i is more efficient total complexity of the code is 0(log(logn))
				is_prime[j]=false;
		}
	}

	for(int i=1;i<=30;i++)
	cout<<i<<" "<<is_prime[i]<<endl;
	return 0;
}