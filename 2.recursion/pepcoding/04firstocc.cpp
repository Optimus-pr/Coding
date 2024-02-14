#include<bits/stdc++.h>
using namespace std;

int firstocc(int *a,int i,int ele,int n)
{
	if(a[i]==ele)
		return i;
	if(i==n-1)
		return -1;
	return firstocc(a,i+1,ele,n);
}

int lastocc(int *a,int i,int ele,int n)
{
	if(i==n-1)
		if(a[i]==ele)
			return i;
		else
			return -1;

	int ans=lastocc(a,i+1,ele,n);

	if(ans!=-1)
		return ans;
	if(a[i]==ele)
		return i;
	return ans;
}

int* alloccu(int *a,int i,int cnt,int ele,int n)
{
	if(i==n)
	{
		return new int[cnt];
	}

	if(a[i]==ele)
	{
		int *b=alloccu(a,i+1,cnt+1,ele,n);
		b[cnt]=i;
		return b;
	}
	else 
	{
		int *b=alloccu(a,i+1,cnt,ele,n);
		return b;
	}

}

int main()
{
	int n;
	cin>>n;

	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	int* b=alloccu(a,0,0,4,n);
	int m=sizeof(b)/2;
	cout<<m<<" "<<endl;
	for(int i=0;i<m;i++)
		cout<<b[i]<<" ";
	return 0;
}