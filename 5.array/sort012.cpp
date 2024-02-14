// 1. we can use sort which takes nlogn time
// 2.we can use count sort i.e keep 3 var and find the occurence of 0 ,1,2 then replace those many 0,1,2 in array this take 0(2n)
// 3.we can use is dutch national flag variation this takes 0(n);



#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++)
		cin>>v[i];

	int l=0,mid=0,h=n-1;

	while(mid<=h)
	{
		if(v[mid]==0)
		{
			swap(v[l],v[mid]);
			l++;mid++;
		}
		else if(v[mid]==1)
			mid++;
		else
		{
			swap(v[mid],v[h]);
			h--;
		}
	}
	for(auto &val:v)
		cout<<val<<" ";
	return 0;
}
















//this take 0(2n)
// #include<bits/stdc++.h>
// using namespace std;

// int main()
// {
// 	int n;
// 	cin>>n;

// 	vector<int> v(n);

// 	for(int i=0;i<n;i++)
// 		cin>>v[i];

// 	int i=0,j=0;

// 	while(j<n)
// 	{
// 		if(v[j]==0)
// 		{
// 			swap(v[i],v[j]);
// 			i++;j++;
// 		}
// 		else
// 			j++;
// 	}
// 	j=i;
// 	while(j<n)
// 	{
// 		if(v[j]==1)
// 		{
// 			swap(v[i],v[j]);
// 			i++;j++;
// 		}
// 		else
// 			j++;
// 	}

// 	for(auto &val:v)
// 		cout<<val<<" ";
// 	cout<<endl;
// 	return 0;
// }