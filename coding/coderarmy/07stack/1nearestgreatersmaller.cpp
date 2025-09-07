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
        int n=arr.size();
        vector<int> v(n,-1);
        stack<int> s;
        
        for(int i=0;i<n;i++)
        {
            while(!s.empty() && arr[s.top()]<arr[i])
            {
                v[s.top()]=arr[i];
                s.pop();
            }
            s.push(i);
        }
        return v;
    }

//same as above but it is just like finding if the pattern is presnet in the rotated text also what we used to do append the same string twice but here we can just run the loop 2*n times 
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