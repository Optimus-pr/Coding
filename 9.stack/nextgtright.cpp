#include<iostream>
#include<stack>
#include<vector> 
using namespace std;

vector<int> nxtgtright(int *a,int n)
{
	stack<int> s;
	vector<int> v;
	for(int i=n-1;i>=0;i--)
	{
		int flag=1;
		if(s.empty())
		{
			v.push_back(-1);
			s.push(a[i]);
		}
		else
		{
			if(a[i]>=s.top())
			{
				while(a[i]>=s.top())
				{
					s.pop();
					if(s.empty())
					{
						v.push_back(-1);
						s.push(a[i]);
						flag=0;
						break;
					}
				}
			}
			if(flag)
			{
				v.push_back(s.top());
				s.push(a[i]);
			}
		}
	}
	return v;

}

vector<int> nxtgtleft(int *a,int n)
{
	stack<int> s;
	vector<int> v;
	for(int i=0;i<n;i++)
	{
		int flag=1;
		if(s.empty())
		{
			v.push_back(-1);
			s.push(a[i]);
		}
		else
		{
			if(a[i]>=s.top())
			{
				while(a[i]>=s.top())
				{
					s.pop();
					if(s.empty())
					{
						v.push_back(-1);
						s.push(a[i]);
						flag=0;
						break;
					}
				}
			}
			if(flag)
			{
				v.push_back(s.top());
				s.push(a[i]);
			}
		}
	}
	return v;

}

vector<int> nxtstleft(int *a,int n)
{
	stack<int> s;
	vector<int> v;
	for(int i=0;i<n;i++)
	{
		int flag=1;
		if(s.empty())
		{
			v.push_back(-1);
			s.push(a[i]);
		}
		else
		{
			if(a[i]<=s.top())
			{
				while(a[i]<=s.top())
				{
					s.pop();
					if(s.empty())
					{
						v.push_back(-1);
						s.push(a[i]);
						flag=0;
						break;
					}
				}
			}
			if(flag)
			{
				v.push_back(s.top());
				s.push(a[i]);
			}
		}
	}
	return v;

}

vector<int> nxtstright(int *a,int n)
{
	stack<int> s;
	vector<int> v;
	for(int i=n-1;i>=0;i--)
	{
		int flag=1;
		if(s.empty())
		{
			v.push_back(-1);
			s.push(a[i]);
		}
		else
		{
			if(a[i]<=s.top())
			{
				while(a[i]<=s.top())
				{
					s.pop();
					if(s.empty())
					{
						v.push_back(-1);
						s.push(a[i]);
						flag=0;
						break;
					}
				}
			}
			if(flag)
			{
				v.push_back(s.top());
				s.push(a[i]);
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

	// vector<int> v=nxtgtright(a,n);
	// reverse(v.begin(),v.end());

	//vector<int> v=nxtgtleft(a,n);

	// vector<int> v=nxtstright(a,n);
	// reverse(v.begin(),v.end());

	vector<int> v=nxtstleft(a,n);
	
	
	for(auto &it:v)
		cout<<it<<" ";
	cout<<endl;
}