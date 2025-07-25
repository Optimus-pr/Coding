int findSubarraywithsum0(vector<int> &arr) {
    unordered_map<int,int> m;
    m[0]=1;
    int ans=0,sum=0;
    for(auto &val:arr)
    {
        sum+=val;
        if(m.find(sum)!=m.end())
            ans+=m[sum];
        m[sum]++;
    }
    return ans;
}

int subarraySum(vector<int>& arr, int k) {
        unordered_map<int,int> m;
        m[0]=1;
        int ans=0,sum=0;
        for(auto &val:arr)
        {
            sum+=val;
            if(m.find(sum-k)!=m.end())
                ans+=m[sum-k];
            m[sum]++;
        }
        return ans;
    }