#include<bits/stdc++.h>
using namespace std;
int n;

void rev(int *a,int i,int j)
{
	if(i>=j)
		return;
	swap(a[i],a[j]);
	rev(a,i+1,j-1);
}

void rev1(int *a,int i)
{
	if(i>=n/2)
		return;
	swap(a[i],a[n-i-1]);
	rev1(a,i+1);
}


int main()
{
	cin>>n;

	int a[n];

	for(int i=0;i<n;i++)
		cin>>a[i];
	rev1(a,0);
	for(auto val:a)
		cout<<val<<" ";
	cout<<endl;
	return 0;
}