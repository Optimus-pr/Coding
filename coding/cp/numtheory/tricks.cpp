#include<bits/stdc++.h>
using namespace std;

void printbin(int n)
{
	for(int i=10;i>=0;i--)
	{
		if((n>>i)&1)
			cout<<"1";
		else
			cout<<"0";
	}
	cout<<endl;
}

void printdeci(string s)
{
	int sum=0,prod=1;
	for(int i=s.size()-1;i>=0;i--)
	{
		sum+=(s[i]-'0')*prod;
		prod*=2;
	}
	cout<<sum;
}

int main()
{
	int n;
	char ch;
	string s;
	cin>>s;
	printdeci(s);
	// cin>>n;
	// cin>>ch;
	// printbin(n);

	// *)calculation of power of 2 without using pow function
	//i.e 2^n is
	// cout<<(1<<n);


	// division by 2
	// cout<<(n>>1)<<" "<<(n<<1)<<endl;

	//conversion of char to uppercase
	// cout<<char(ch&'_');
	//conversion to lowercase
	// cout<<char(ch|' ');




	return 0;
}