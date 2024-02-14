//dijikstra's was there but why we need belmanford bcause dijkstra's don't work for -ve edge weights and particularly -ve weighted cycles it will fall in infinite loop

// it is same as dijkstra's but here we have to run for v-1 times as in worst case we may not get the vertex with distance of zero

//again we need to check for one more time so as to know if there exists negative wted cycle which we will come to know if there is any chance for reduction of the weights if there is no cycle then there will be max of V-1 cycles for which the dis vector will be modified further there is no change in it if there is no cycle

//dijkstra's will go infinite loop but bellman_ford won't 

vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
       
        vector<int> dis(V,1e8);
        dis[S]=0;
        
        for(int i=0;i<V-1;i++)
        {
            for(auto &val:edges)
            {
                int x=val[0],y=val[1],wt=val[2];
                if(dis[x]!=1e8 && dis[x]+wt<dis[y])
                    dis[y]=dis[x]+wt;
            }
        }
        
        for(auto &val:edges)
        {
            int x=val[0],y=val[1],wt=val[2];
            if(dis[x]!=1e8 && dis[x]+wt<dis[y])
                return {-1};//after v-1 iterations here changes is being done so there is cycle so return -1;
        }
        
        return dis;
    }