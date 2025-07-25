int findPages(vector<int> &nums, int m)  {
        int n=nums.size(),mx=0,sum=0,mid;
        if(n<m)
            return -1;
        for(auto &val:nums)
        {
            mx=max(mx,val);
            sum+=val;
        }
        int s=mx,e=sum,ans=-1;
        while(s<=e)
        {
            mid=(s+e)/2;
            int cnt=1,pages=0;
            for(int i=0;i<n;i++)
            {
                pages+=nums[i];
                if(pages>mid)
                {
                    cnt++;
                    pages=nums[i];
                }
            }
            if(cnt<=m)
            {
                ans=mid;
                e=mid-1;
            }
            else
                s=mid+1;
        }
        return ans;
    }