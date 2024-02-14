#include<bits/stdc++.h>
using namespace std;

int t[10]={0};

int frog(int *a,int n)
{
	t[0]=0;
	t[1]=abs(a[1]-a[0]);

	for(int i=2;i<n;i++)
	{
		int op1=abs(a[i]-a[i-1])+t[i-1];
		int op2=abs(a[i]-a[i-2])+t[i-2];

		t[i]=min(op1,op2);
	}
	return t[n-1];
}

int main()
{
	int a[]={30,10,60,10,60,50};
	cout<<frog(a,6);
	return 0;

}