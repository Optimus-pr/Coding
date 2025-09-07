#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,cnt=0,sum=0;
	cin>>n;

	for(int i=1;i*i<=n;i++)
	{
		if(n%i==0)
		{
			cout<<i<<" ";
			cnt+=1;
			sum+=i;
			if(i!=n/i)
			{
				cout<<n/i<<endl;
				cnt+=1;
				sum+=n/i;
			}
		}
	}
	cout<<cnt<<" "<<sum<<endl;
	return 0;

}