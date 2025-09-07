#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,temp;
	cin>>n;
	temp=n;
	int rev=0,ld;

	while(n)
	{
		ld=n%10;
		rev=rev*10+ld;
		n/=10;
	}
	if(rev==temp)
		cout<<"palindrome";
	else
		cout<<"not a palindrome";
	return 0;
}
