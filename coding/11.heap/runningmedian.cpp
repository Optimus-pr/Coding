#include<bits/stdc++.h>
using namespace std;

vector<float> median(int *a,int n)
{
	priority_queue<int> left;
	priority_queue<int,vector<int>,greater<int> > right;
	vector<float> v;
	// v.push_back(a[0]);
	left.push(a[0]);
	float med=a[0];
	v.push_back(med);

	for(int i=1;i<n;i++)
	{
		int ltsize=left.size();
		int rtsize=right.size();

		if(ltsize==rtsize)
		{
			if(a[i]<left.top())
			{
				left.push(a[i]);
				med=left.top();
				v.push_back(left.top());
			}
			else
			{
				right.push(a[i]);
				med=right.top();
				v.push_back(right.top());
			}
		}
		else if(ltsize>rtsize)
		{
			if(a[i]<left.top())
			{
				right.push(left.top());
				left.pop();
				left.push(a[i]);
			}
			else
				right.push(a[i]);

			med=(left.top()+right.top())/2.0;
			v.push_back(med);
		}
		else
		{
			if(a[i]<left.top())
				left.push(a[i]);
			else
			{
				left.push(right.top());
				right.pop();
				right.push(a[i]);
			}

			med=(left.top()+right.top())/2.0;
			v.push_back(med);
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
	vector<float> v=median(a,n);

	for(auto &val:v)
		cout<<val<<" ";
	cout<<endl;
	return 0;
}