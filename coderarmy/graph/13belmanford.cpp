//dijikstra was not working for -ve wt so belmanford came which will work for -ve wts but not -ve wt cycle i.e if we sum up the wts of the cycle then it will be -ve but it detects -ve wtd cycle and returns {-1} in this case

//dijikstra algorithm primarily works on the vertex concept but belman ford focuses on edjes

//this algo is easiest in graph ig nothing fancy just keep on relaxing the edges V-1 times relaxing in the sense d[v]+wt<d[child] then update d[child], initially we will make d[src]=0

//here why V-1 times?
//say 1->2->3->4 src is 1 so dis vertext will be 0 inf inf now say the order given in the edges matrix is 3 4 1,2 3 4,1 2 3 it requires complete V-1 times to get the ans but if ulta i.e 1 2 3, 2 3 4, 3 4 1 was given then in the first iteration only we would have got the ans so rest v-2 iteration will go in waste so to identify that only we keep flag if d[] doesn't change in a iteration then it means that we have got ans for shortest path from src to all the nodes and there is no cycle but worst case we need V-1 times as we can't rely on the order in which vertex will be given


//if -ve wted cycle is present then after relaxing the edges for v-1 times also still the d vertex will be updated so => cycle

vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
    
        vector<int> d(V,1e8);
        d[src]=0;
        int cnt=V-1;
        bool flag=false;
        
        while(cnt--)
        {
            flag=0;
            for(auto &val:edges)
            {
                if(d[val[0]]!=1e8 && d[val[0]]+val[2]<d[val[1]]){
                    flag=1;
                    d[val[1]]=d[val[0]]+val[2];
                }
            }
            if(flag==0)
                return d;
        }
        flag=0;
        for(auto &val:edges)
        {
            if(d[val[0]]!=1e8 && d[val[0]]+val[2]<d[val[1]]){
                flag=1;
                d[val[1]]=d[val[0]]+val[2];
            }
        }
        if(flag)
            return {-1};
        return d;
    }