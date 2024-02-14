#include<bits/stdc++.h>
using namespace std;

void rec(int n)
{
	if(n==0)
		return;
	cout<<n<<endl;
	rec(n-1);
	cout<<n<<endl;
}

int main()
{
	int n;
	cin>>n;

	rec(n);
	return 0;
}