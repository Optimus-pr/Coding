//armstrong number

// 153=1^3+5^3+3^3;
// 1634=1^4+6^4+3^4+4^4

#include<bits/stdc++.h>
using namespace std;

int power(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b&1)
			ans*=a;
		a*=a;
		b>>=1;
	}
	return ans;
}

int main()
{
	int n;
	cin>>n;

	int temp=n,sum=0,ld,cnt;
	cnt=floor(log10(n)+1);

	while(n)
	{
		ld=n%10;
		sum+=power(ld,cnt);
		n/=10;
	}

	if(temp==sum)
		cout<<"Armstrong";
	else
		cout<<"Not Armstrong";
	return 0;
}