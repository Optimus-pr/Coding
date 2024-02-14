#include<bits/stdc++.h>
using namespace std;

int partition(int *a,int l,int h)
{
	int p=a[l],i=l+1,j=h,temp;

	while(i<=j)//equals is must or in case of 1 2 3 4 we get 1 2 4 3 as output
	{
		while(i<=h && a[i]<p)
			i++;
		while(a[j]>p)
			j--;
		if(i<=j)
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
			i++;
			j--;
		}
	}

	temp=a[l];
	a[l]=a[j];
	a[j]=temp;

	return j;
}


void qsort(int *a,int l,int h)
{
	if(l<=h)
	{
		int s=partition(a,l,h);
		qsort(a,l,s-1);
		qsort(a,s+1,h);
	}
}

int main()
{
	int n;
	cin>>n;

	int a[n];

	for(int i=0;i<n;i++)
		cin>>a[i];
	qsort(a,0,n-1);

	for(auto &it:a)
		cout<<it<<" ";


}