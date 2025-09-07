//here we need to find the len of max subarr with atmost freq of each element k

int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int i=0,j=0,n=nums.size(),mx=INT_MIN;
        while(j<n)
        {
            auto & cnt = ++m[nums[j]];
            while (cnt > k)
            {
                --m[nums[i++]];
            }
            mx=max(mx,j-i+1);
            j++;
        }
        return mx;
    }