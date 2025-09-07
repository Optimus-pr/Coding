//aim is to find lowest element to the left and right so that we can do a[i]*(ll-lr-1)

#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector<int> left(int *a,int n)
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
			if(a[i]<=a[s.top()])
			{
				while(a[i]<=a[s.top()])
				{
					s.pop();
					if(s.empty())
					{
						flag=0;
						v.push_back(-1);
						s.push(i);
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

vector<int> right(int *a,int n)
{
	vector<int> v;
	stack<int> s;

	for(int i=n-1;i>=0;i--)
	{
		int flag=1;
		if(s.empty())
		{
			v.push_back(n);
			s.push(i);
		}
		else
		{ 
			if(a[i]<=a[s.top()])
			{
				while(a[i]<=a[s.top()])
				{
					s.pop();
					if(s.empty())
					{
						flag=0;
						v.push_back(n);
						s.push(i);
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

	vector<int> lt=left(a,n);
	vector<int> rt=right(a,n);
	reverse(rt.begin(),rt.end());

	// for(auto &it:a)
	// 	cout<<it<<" ";
	// cout<<endl;

	// for(auto &it:lt)
	// 	cout<<it<<" ";
	// cout<<endl;

	// for(auto &it:rt)
	// 	cout<<it<<" ";
	// cout<<endl;
	int ar=-9999,mar=-9999;
	for(int i=0;i<n;i++)
	{
		ar=(rt[i]-lt[i]-1)*a[i];
		mar=max(ar,mar);
	}
	cout<<mar<<endl;

}