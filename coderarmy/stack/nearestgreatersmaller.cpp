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