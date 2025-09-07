#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;

	int a[n];

	for(int i=0;i<n;i++)
		cin>>a[i];

	int max1=-9999,max2=-9999;
	int min1=9999,min2=9999;
	
	for(int i=0;i<n;i++)
	{
		if(a[i]>max1)
		{
			max2=max1;
			max1=a[i];
		}
		else if(a[i]>max2 && a[i]!=max1)
			max2=a[i];


		if(a[i]<min1)
		{
			min2=min1;
			min1=a[i];
		}
		else if(a[i]<min2 && a[i]!=min1)
			min2=a[i];
	}

	cout<<max2<<" "<<min2<<endl;
	return 0;
		
}