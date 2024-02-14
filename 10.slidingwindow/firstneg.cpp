//aim is to find the first -ve no in window of size k if no -ve no exists then print 0

#include<bits/stdc++.h>
using namespace std;

void  printmin(int *a,int n)
{
	queue<int> q;
	int i=0,j=0;

	while(j<n)
	{
		if(a[j]<0)
			q.push(a[j]);
		if(j-i+1<3)
			j++;
		else if(j-i+1==3)
		{
			if(!q.empty())
			cout<<q.front()<<" ";
		else
			cout<<"0"<<" ";

			if(a[i]<0 && !q.empty())
				q.pop();
			i++;
			j++;
		}
	}
}

int main()
{
	int n;
	cin>>n;

	int a[n];

	for(int i=0;i<n;i++)
		cin>>a[i];

	printmin(a,n);
}