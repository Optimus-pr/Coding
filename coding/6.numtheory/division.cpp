#include<iostream>

using namespace std;

int main()
{
	int divisor,dividend,sign;
	cin>>divisor>>dividend;

	sign=((dividend<0)^(divisor<0))?-1:1;

	int q=0;

	dividend=abs(dividend);
	divisor=abs(divisor);

	// while(dividend>=divisor)
	// {
	// 	dividend-=divisor;
	// 	q++;
	// }



	// for(int i=31;i>=0;i--)
	// {
	// 	if((divisor<<i)<=dividend)
	// 	{
	// 		dividend-=(divisor<<i);
	// 		q|=1<<i;
	// 	}
	// }
	cout<<q*sign;
}
