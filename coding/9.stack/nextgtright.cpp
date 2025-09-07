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

vector<int> nsl(vector<int> arr) {
        // code here
        int n=arr.size();
        vector<int> v(n,-1);
        stack<int> s;
        
        for(int i=n-1;i>=0;i--)
        {
            while(!s.empty() && arr[s.top()]>arr[i])
            {
                v[s.top()]=arr[i];
                s.pop();
            }
            s.push(i);
        }
        return v;
    }

vector<int> ngr(vector<int> &arr) {
        stack<int> s;
        int n=arr.size();
        vector<int> v(n,-1);
        for(int i=0;i<2*n;i++)
        {
            while(!s.empty() && arr[s.top()]<arr[i%n])
            {
                v[s.top()]=arr[i%n];
                s.pop();
            }
            s.push(i%n);
        }
        return v;
    }

 vector<int> ngrincircularq(vector<int>& nums) {
        int n=nums.size();
        vector<int> v(n,-1);
        stack<int> s;
        for(int i=0;i<2*n;i++)
        {
            while(!s.empty() && nums[s.top()]<nums[i%n])
            {
                v[s.top()]=nums[i%n];
                s.pop();
            }
            s.push(i%n);
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