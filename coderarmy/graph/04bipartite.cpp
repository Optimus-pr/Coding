//bfs

bool isBipartite(int V, vector<vector<int>> &edges) {
        // Code here
        vector<int> g[V];
        for(auto &val:edges)
        {
            g[val[0]].push_back(val[1]);
            g[val[1]].push_back(val[0]);
        }
        
        vector<int> color(V,-1);
        
        queue<int> q;
        q.push(0);
        color[0]=0;
        
        while(!q.empty())
        {
            int v=q.front();
            q.pop();
            
            for(auto &child:g[v])
            {
                if(color[child]==color[v])
                    return false;
                if(color[child]==-1)
                {
                    q.push(child);
                    color[child]=!color[v];
                }
            }
        }
        return true;
    }

//dfs

bool dfs(vector<int> g[],vector<int> &vis,int v,int clr)
    {
        vis[v]=clr;
        
        for(auto &child:g[v])
        {
            if(vis[child]==-1)
                if(dfs(g,vis,child,!clr)==false)
                    return false;
            if(vis[child]==vis[v])
                return false;
        }
        return true;
    }
  
    bool isBipartite(int V, vector<vector<int>> &edges) {
        // Code here
        vector<int> g[V];
        for(auto &val:edges)
        {
            g[val[0]].push_back(val[1]);
            g[val[1]].push_back(val[0]);
        }
        
        vector<int> vis(V,-1);
        
        for(int i=0;i<V;i++)
            if(vis[i]==-1)
                if(dfs(g,vis,i,0)==false)
                    return false;
        return true;
        
    }