//here we need to count the no of subarrays with mx occuring atleast k times in each sub arary

long long countSubarrays(vector<int>& nums, int k) {
        int  mx=nums[0],n=nums.size();
        for(int i=1;i<n;i++)
            mx=max(mx,nums[i]);
        long long i=0,j=0,cnt=0,ans=0;
        while(j<n)
        {
            if(nums[j]==mx)
                cnt++;
                
            while(cnt>=k)
            {
                ans+=(n-j);//1 2 3 3 4 5 6  and 2 is k here 1 2 3 3 has 3 >=2 no need to check further becuase all other instances will also have these 3 2 times so direcly add (n-j) here
                if(nums[i]==mx)
                    cnt--;
                i++;
            }
            j++;
        }
        return ans;
    }