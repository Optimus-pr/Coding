//this is dfs way of finding cycle in the graph

bool dfsCycle(vector<int> arr[],vector<bool> &vis,int v,int p)
    {
        vis[v]=1;
        for(auto &child:arr[v])
        {
            if(child==p)
                continue;
            if(vis[child]==1)   
                return 1;
            if(dfsCycle(arr,vis,child,v))return true;
        }
        return false;
    }
    
//this is bfs way of finding cycle
    bool bfsCycle(vector<int> arr[],vector<bool> &vis,int v)
    {
        queue<pair<int,int> > q;
        q.push({v,-1});
        vis[v]=1;
        
        while(!q.empty())
        {
            int ver=q.front().first;
            int p=q.front().second;
            
            q.pop();
            
            for(auto &child:arr[ver])
            {
                if(child==p)
                    continue;
                if(vis[child])
                    return 1;
                
                q.push({child,ver});
                vis[child]=1;
            }
        }
        return 0;
    }
    
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<bool> vis(V,0);
        vector<int> edge[V];
        for(auto &val:edges)
        {
            edge[val[0]].push_back(val[1]);
            edge[val[1]].push_back(val[0]);
        }
        for(int i=0;i<V;i++)
        if(vis[i]==0 && dfsCycle(edge,vis,i,-1))
            return true;
        return false;
        
    }