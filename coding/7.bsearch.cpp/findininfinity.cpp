//here elements are sorted but there exists infinite number of elements so we need to start l from 0th index and h from 1st index check if a[h]<key then do h=h*2; until the key lie between l and h we do the same then we follow normal bs

#include<iostream>
using namespace std;



int bs(int *a,int l,int h,int key)
{
	int mid;

	while(a[h]<key)
		h*=2;

	while(l<=h)
	{
		mid=h +(l-h)/2;
		if(a[mid]==key)
			return mid;
		else if(a[mid]>key)
			h=mid-1;
		else
			l=mid+1;
	}
	return -1;
}

int main()
{
	int n,key;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	cin>>key;

	cout<<bs(a,0,1,key);

	return 0;
}