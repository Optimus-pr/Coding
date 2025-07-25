#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,ans=0,mul=1;
	cin>>n;
	while(n)
	{
	    int rem=n%2;
	    n=n/2;
	    ans=rem*mul+ans;
	    mul*=10;
	}
	cout<<ans;

}
