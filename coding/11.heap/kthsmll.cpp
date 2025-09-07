//this will return the kth smallest number if we use traditional sorting method it takes 0(nlogn) i.e assuem in 7 10 4 3 20 15 if k was 3 out will be 7 if sorting used the unnesseary 10 20 15 are also sorted so it adds additional time but now since we are using heap it takes nlog(k) time as we are just sorting k items... since min ele is required we will create maxheap here the greatest ele always lies on the top of heap in order to create a max heap we must create like this i.e priority_queue<int> maxhp;

#include<bits/stdc++.h>
using namespace std;

int kthsmall(int *a,int n,int k)
{
	priority_queue<int> maxhp;
	for(int i=0;i<n;i++)
	{
		maxhp.push(a[i]);

		if(maxhp.size()>k)
			maxhp.pop();
	}

	return maxhp.top();
}

int main()
{
	int n,q,k;
	cin>>n;
	 int a[n];

	 for(int i=0;i<n;i++)
	 	cin>>a[i];

	 cin>>k;

	 cout<<kthsmall(a,n,k);
}