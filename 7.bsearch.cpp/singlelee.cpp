//1 1 2 3 3 4 4  here we need to output 2 as it is the only single ele we could have used xor but it take 0(n) in order to optimise it we can go with bsearch

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;

	int a[n];

	for(int i=0;i<n;i++)
		cin>>a[i];

	int l=0,h=n-2;//-----
	while(l<=h)
	{
		int mid=(l+h)/2;
		if(a[mid]==a[mid^1])//even say 4 xor 1 will give 5 odd say 3 xor 1 will give 2 
			l=mid+1;
		else
			h=mid-1;
	}
	cout<<a[l];
}