//Given start, end and an array arr of n numbers. At each step, start is multiplied with any number in the array and then mod operation with 100000 is done to get the new start.

//Your task is to find the minimum steps in which end can be achieved starting from start. If it is not possible to reach end, then return -1.


int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
    queue<pair<int,int> > q;
    q.push({0,start});
    vector<int> d(99999,1e6);
    
    while(!q.empty())
    {
        int n=q.top().first,val=q.top().second;q.pop();
        
        if(val%100000==end)
            return n;
        
        for(auto &info:arr)
        {
             int mul=(val*info)%100000;
             if(d[mul]==1e6)
             {
                   q.push({n+1,mul});
                   d[mul]=n+1;
             }
              
        }
           
    }
    return -1;
}