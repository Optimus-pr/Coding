/*
	this approach takes 0(3n)~ 0(n)
	1.find the first element's index which is smaller than the nxt ele from right if u don't find one then goto step 5
	2.find the first ele's index which is greater than the ele found in previous step traverse from right
	3.swap ele in the corresponding indicies
	4.now reverse from index+1 till end
	5.reverse entire array
*/


#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;

	int a[n];

	for(int i=0;i<n;i++)
		cin>>a[i];

	int in1=-1,in2;

	for(int i=n-2;i>=0;i--)
	{
		if(a[i]<a[i+1])
		{
			in1=i;
			break;
		}
	}

	if(in1!=-1)
	{
		for(int i=n-1;i>=0;i--)
		{
			if(a[i]>a[in1])
			{
				in2=i;
				break;
			}
		}
		
		swap(a[in1],a[in2]);

		reverse(a+in1+1,a+n);
	}
	else
		reverse(a,a+n);


	for(auto &val:a)
		cout<<val<<" ";
	return 0;

}