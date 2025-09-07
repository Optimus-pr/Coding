//x is double and y is int it can be -ve also for negative just follow the same procedure which we do for +ve at last divide 1 with that answer but 1 thing to take care we know that int range is from -32768 to 32767 so we if power is -32768 when we convert it into +ve value it will overflow so make sure to take long datatype

#include <bits/stdc++.h>
using namespace std;

int main()
{
	double x;
	int n;

	cin>>x>>n;

	long nn=n;

	if(nn<0)
		nn*=-1;

	double ans=1.0;

	while(nn)
	{
		if(nn&1)
			ans*=x;
		x*=x;
		nn>>=1;
	}

	if(n<0)
		cout<<(1/ans);
	else
		cout<<ans;


}