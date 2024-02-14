#include<bits/stdc++.h>
using namespace std;

double eps=1e-5;

int main()
{
	double n;
	cin>>n;
	double l=1,h=n;

	while(h-l>eps)
	{
		double mid=(h+l)/2;
		if(mid*mid>n)
			h=mid;
		else
			l=mid;
	}
	cout<<setprecision(4)<<l<<" "<<h;
	return 0;
}