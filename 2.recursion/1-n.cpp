#include<bits/stdc++.h>
using namespace std;

void rec(int n)
{
	if(n==0)return;
	rec(n-1);
	cout<<n<<endl;
}//if order of line 7 8 are changed then descending order will be printed.

int main()
{
	int n;
	cin>>n;
	rec(n);
	return 0;	
}