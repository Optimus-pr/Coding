#include<bits/stdc++.h>
using namespace std;

int cnt=0;

int merg(int *a,int *b,int l,int mid,int n)
{	
	int i=l,k=l,j=mid+1,invcnt=0;
	while(i<=mid && j<=n)
	{
		if(a[i]<=a[j])
			b[k++]=a[i++];
		else 
		{
			b[k++]=a[j++];
			 cnt+=mid-i+1;//2 3 5    2 2 4 4 8  here 3>2=>all the ele after 3 is also greater than 2 so not just cnt++ cnt+=(mid-l+1)
		}
	}

	for(;i<=mid;)
		b[k++]=a[i++];

	for(;j<=n;)
		b[k++]=a[j++];
	for(int c=l;c<=n;c++)
		a[c]=b[c];
	
}

int msort(int *a,int *b,int l,int r)
{
	int mid,invcnt=0;
	if(l<r)
	{
		mid=(l+r)/2;
		msort(a,b,l,mid);
		msort(a,b,mid+1,r);
		merg(a,b,l,mid,r);
	}
}

int main()
{
	int n;
	cin>>n;

	int a[n],b[n];

	for(int i=0;i<n;i++)
		cin>>a[i];

	msort(a,b,0,n-1);

	// for(auto &val:a)//printing b also works
	// 	cout<<val<<" ";
	return 0;
}