#include<bits/stdc++.h>
using namespace std;

int bs(int n)
{
	int l=1,h=n,ans;
	while(l<=h)
	{
		int mid=(l+h)/2;
		if(mid*mid<=n)
		{
			ans=mid;
			l=mid+1;
		}
		else
			h=mid-1;
	}
	return ans;

}

int main()
{
	int n,p;
	cin>>n>>p;

	float ans=bs(n);
	// cout<<ans;

	float inc=0.1;

	for(int i=1;i<=p;i++)
	{
		while(ans*ans<=n)
			ans+=inc;
		ans-=inc;
		inc/=10;
	}
	cout<<ans;

	return 0;
}