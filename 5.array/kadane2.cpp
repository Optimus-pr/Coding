//this is used to give the max subarray circular sum i.e 8 -4 3 -5 4 normal kadane will return 8 but circular kadane will return 12

#include<bits/stdc++.h>
using namespace std;

int kadane(int *a,int n)
{
	int sum=a[0],mx=a[0];
	if(sum<0)
		sum=0;
	for(int i=1;i<n;i++)
	{
		sum+=a[i];
		mx=max(sum,mx);
		if(sum<0)
			sum=0;
	}
	return mx;
}

int main()
{
	int a[]={3,-4,5,6,-8,7};
	int n=sizeof(a)/sizeof(int);
	int kadan=kadane(a,n);
	if(kadan<0)
	{
		cout<<kadan;
		return 0;
	}

	//this is for finding minimum subarray sum
	int sum=0;
	for(int i=0;i<n;i++)
	{
		sum+=a[i];
		a[i]=-a[i];
	}

	int kadan2=sum+kadane(a,n);
	cout<<max(kadan,kadan2);
	return 0;

}