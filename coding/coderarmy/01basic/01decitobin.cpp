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


// if we get stream of numbers 2 3 4 5 and we need to from no 2345 then we can do ans=ans*10+rem
// 	but if we want 5432 to be formed then?

// ans=ans*mul+rem;//mul will be init 1
// mul*=10;

// the same we can use in computing binary from decimal as we will get rem in rev order 

// anyway we can do binary to decimal and octal to decimal easily likewise if binary to octal is the ask then convert binary to decimal first then decimal to octal as we did for binary in the above case just rem by 8;/=8;