//3 variation of this kind of problem



#include<bits/stdc++.h>
using namespace std;

//1. is to print all the possible seq which gives the req sum where each element is used only once
void printsub(int *a,vector<int> b,int n,int i,int sum)
{
	if(i==n)
	{
		if(sum==0)
		{
			for(auto it:b)
				cout<<it<<" ";
			cout<<endl;
		}
		return;
	}

	b.push_back(a[i]);
	printsub(a,b,n,i+1,sum-a[i]);
	b.pop_back();

	printsub(a,b,n,i+1,sum);
}



// 2.print only 1 sub seq
// bool printsub(int *a,vector<int> b,int n,int i,int sum)
// {
// 	if(i==n)
// 	{
// 		if(sum==0)
// 		{
// 			for(auto it:b)
// 				cout<<it<<" ";
// 			cout<<endl;
// 			return true;
// 		}
// 		return false;
// 	}

// 	b.push_back(a[i]);
// 	if(printsub(a,b,n,i+1,sum-a[i]))return true;
// 	b.pop_back();

// 	if(printsub(a,b,n,i+1,sum))return true;
// }



//to print the number of subseq present which gives the required sum
// int printsub(int *a,vector<int> b,int n,int i,int sum)
// {
// 	if(i==n)
// 	{
// 		if(sum==0)
// 			return 1;
		
// 		return 0;
// 	}
// -
// 	b.push_back(a[i]);
// 	int l=printsub(a,b,n,i+1,sum-a[i]);
// 	b.pop_back();

// 	int r=printsub(a,b,n,i+1,sum);
// 	return l+r;
// }

int main()
{
	int n,sum;
	cin>>n>>sum;

	int a[n];

	for(int i=0;i<n;i++)
		cin>>a[i];

	vector<int> b;

	printsub(a,b,n,0,sum);
}