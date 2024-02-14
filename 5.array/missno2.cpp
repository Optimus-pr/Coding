// the below approach takes 0(1) time and 0(n) space for map

// #include<bits/stdc++.h>
// #include<unordered_map>
// using namespace std;

// int main()
// {
// 	int n,sum=0,dub;
// 	cin>>n;

// 	vector<int> v(n);
// 	for(int i=0;i<n;i++)
// 	{
// 		cin>>v[i];
// 		sum+=v[i];
// 	}

// 	unordered_map<int,int> u;

// 	for(auto &val:v)
// 		u[val]++;

// 	int exp=n*(n+1)/2;

// 	for(auto it:u)
// 	{
// 		if(it.second!=1)
// 		{
// 			dub=it.first;
// 			break;
// 		}
// 	}
// 	cout<<"replace "<<dub<<" by "<<(exp-(sum-dub))<<endl;
// 	return 0;

// }


// 2)

// sum array(x) - sum upto n(y)=a

// sum of sqaures of array(x^2)-sum of square upto n(y^2)=b

// here x is missing and y


we can simply use swap sort i.e at pos i ele i+1 should be present eg if it is 3 2 2 then at 0 1 should be present which is not there so swap a[3-1] with a[0] now we will have 2 2 3 now check a[2-1]=2 yes so just i++ again a[1]==2 ? yes continue now a[2]=3 yes now we have 2 2 3 now check if at index i we have element i+1 if not then i+1 is the missing no and element present at that index is dublicate

this works for single dub and missing or multiple but this and this code doesn't consume extra space as done in above method but if the given vector is const then we can't do modification in it so at that time we can go with the below approach


#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;

	vector<int> v(n);

	for(int i=0;i<n;i++)
		cin>>v[i];

	int xor1=0;

	for(int i=0;i<n;i++)
		xor1=xor1^v[i];
	for(int i=1;i<=n;i++)
		xor1=xor1^i;
	//xor1 will be xor of missing and repeating number
	int i=xor1 & ~(xor1-1);
	// find no i such that xor1's rightmost bit is 1 i.e if xor1 is 4 i will also be 4 if xor1 is 3 then i will be 1

	int x=0,y=0;

	for(int j=0;j<n;j++)
	{
		if(v[j]&i)
			x=x^v[j];
		else 
			y=y^v[j];
	}

	for(int j=1;j<=n;j++)
	{
		if(j&i)
			x=x^j;
		else 
			y=y^j;
	}
	//x and y may be swapped
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		if(x==v[i])
		{
			swap(x,y);
			break;
		}
	}
	cout<<x<<" "<<y<<endl;
	return 0;

}