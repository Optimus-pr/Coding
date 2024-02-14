//moore's voting algorithm
//majority ele is one which is present >= n/2 times

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,cnt=0,majority=0;
	cin>>n;

	int a[n];

	for(int i=0;i<n;i++)
		cin>>a[i];

	for(auto &val:a)
	{
		if(cnt==0)
			majority=val;

		if(val==majority)
			cnt++;
		else 
			cnt--;
	}
	int tmp=0;
	for(int i=0;i<n;i++)
		if(a[i]==majority)
			tmp++;
	if(tmp<=n/2)
		cout<<"-1";
	else
		cout<<majority;
}

