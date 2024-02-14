#include<bits/stdc++.h>
using namespace std;

void printseq(int *a,vector<int> b,int n,int i)
{
	if(i==n)
	{
		for(auto it:b)
			cout<<it<<" ";
		cout<<endl;
		return;
	}

	b.push_back(a[i]);
	printseq(a,b,n,i+1);
	b.pop_back();

	printseq(a,b,n,i+1);
}

int main()
{
	int n;
	cin>>n;

	int a[n];
	vector<int> b;

	for(int i=0;i<n;i++)
		cin>>a[i];

	printseq(a,b,n,0);

}