//A pair of indices (i, j) is a bad pair if i < j and j - i != nums[j] - nums[i].

==> j-nums[j]==i-nums[i]  so just keep track of this pos-val in map whenever we get same value we can just add the previous value to ans then we can update the value by 1 this will give us no of good pairs we know that n*(n-1)/2 is the total no of pairs that can be formed so sub no of good pairs from that we will get the required answer


long long countBadPairs(vector<int>& nums) {
        long long ans=0;
        int n=nums.size();
        unordered_map<int,int> m;
        for(int i=0;i<n;i++)
        {
            int x=i-nums[i];
            if(m.find(x)!=m.end())
                ans+=m[x];
            m[x]++;
        }
        return n*1LL*(n-1)/2-ans;
}