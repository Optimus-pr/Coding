void merge(vector<int> &a,vector<int> &b)
    {
        vector<int> ans;
        int i=0,j=0;
        while(i<a.size() && j<b.size())
        {
            if(a[i]<=b[j])
                ans.push_back(a[i++]);
            else
                ans.push_back(b[j++]);
        }
        while(i<a.size())
            ans.push_back(a[i++]);
        while(j<b.size())
            ans.push_back(b[j++]);
        a=ans;
    }
    
    vector<int> mergeKArrays(vector<vector<int>> v, int K)
    {
        for(int i=1;i<K;i++)
            merge(v[0],v[i]);
        return v[0];
        
    }