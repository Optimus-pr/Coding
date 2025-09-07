// prims algo unlike kruskal who will add all the edges in pq this will start from ver and puts the lowest wt edje and make it as visisted

int spanningTree(int V, vector<vector<int>> adj[]) {
        // code here
        vector<int> vis(V,0);
        priority_queue<pair<int,int>,vector<pair<int,int> > ,greater<pair<int,int> > > q;
        q.push({0,0});
        int cost=0;
        
        while(!q.empty())
        {
            int wt=q.top().first,v=q.top().second;
            q.pop();
            if(vis[v]==0)
            {
                vis[v]=1;
                cost+=wt;
            }
            
            for(auto &val:adj[v])
            {
                int child=val[0],wtt=val[1];
                if(!vis[child])
                    q.push({wtt,child});
            }
        }
        return cost;
    }