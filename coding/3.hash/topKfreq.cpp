    static bool cmp(pair<int,int> a,pair<int,int> b)
    {
        if(a.first!=b.first)
        {
            return a.second>b.second;
        }
        return a.first>b.first;
    }
    
    vector<int> topK(vector<int>& nums, int k) {
        //map<int,int,decltype(cmp)> u(cmp);map cannot be sorted as it is inbuilt sorted about the key but if we want to sort it we need to use a third parameter decltype(cmp) where cmp is an comparator fun 
        unordered_map<int,int> u;
        for(int i=0;i<nums.size();i++)
        {
            u[nums[i]]++;
        }
        vector< pair<int,int> > v(u.begin(),u.end());
        //unorderedmap doesn't support forward iterators i.e we cannot use u.begin,u.end inside sort so we need to do as above which will copy instance of umap inside vector<pair<int,int> > since vector supports forward iterators we can use it for sorting purpose;
        
        sort(v.begin(),v.end(),cmp);
        v.erase(v.begin()+k,v.end());
       
        nums.clear();
        for(auto val:v)
        {
            nums.push_back(val.first);
        }
        return nums;
    }