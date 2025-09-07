bool isProduct(vector<int> arr, long long x) {
        // code here
        unordered_map<float,int> m;
        int n=arr.size();
        for(int i=0;i<n;i++)
            m.insert({arr[i],i});
        for(int i=0;i<n;i++)
        {
            if(m.find(x*1.0/arr[i])!=m.end() && m[x*1.0/arr[i]]!=i)
                return true;
        }
        return false;
    