//this program tells to find the consecutive smaller elements to the left but this can be indirectly achieved by finding the next greater element to the left instead of storing the element in the result vec store the index in it


#include<bits/stdc++.h>
using namespace std;

vector<int> stock(int *a,int n)
{
	vector<int> v;
	stack<int> s;

	for(int i=0;i<n;i++)
	{
		int flag=1;
		if(s.empty())
		{
			v.push_back(-1);
			s.push(i);
		}
		else
		{
			if(a[i]>=a[s.top()])
			{
				while(a[i]>=a[s.top()])
				{
					s.pop();
					if(s.empty())
					{
						v.push_back(-1);
						s.push(i);
						flag=0;
						break;
					}
				}
			}
			if(flag)
			{
				v.push_back(s.top());
				s.push(i);
			}
		}
	}
	return v;
}

int main()
{
	int n;
	cin>>n;

	int a[n];

	for(int i=0;i<n;i++)
		cin>>a[i];

	vector<int> v=stock(a,n);//this vector will have nxtgtleft ele's index but we don't need it we need the number of consecutive elements smaller than the curent element so we can just sub vector's index with the corresponding index of the maxeletoright

	for(int i=0;i<n;i++)
		cout<<v[i]<<" ";
	cout<<endl;

	for(int i=0;i<n;i++)
		cout<<i-v[i]<<" ";
	cout<<endl;

	return 0;
}