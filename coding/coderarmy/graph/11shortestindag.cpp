    // 1-->2-->3-->4
    // |       |
    // |       |
    // 5-->6-->7

    // say in the above graph if we go with bfs then ver 3 will be visiter first like wise it will go with computatoin of distance of vertex 4 this was good in case of undirected uniwt graphs but here it is better to go with dfs 

    // so say if we go with dfs we compute 3 and ver 4's distance later again in path 5  again we computer 3 and 4 if distance is less we compute again so complexity will raise again

    // so better do topological sort first and then take out each vertex and then start relaxing each vertex
    // doing this will prevent unnecessary complexity 




    void topo(vector<pair<int,int> > g[],stack<int> &s,int ver,vector<bool> &vis)
    {
        vis[ver]=1;
        
        for(auto &child:g[ver])
        {
            if(vis[child.first])
                continue;
            topo(g,s,child.first,vis);
        }
        s.push(ver);
    }
  
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector<pair<int,int> > g[V];
        vector<int> d(V,INT_MAX);
        for(auto &val:edges)
            g[val[0]].push_back({val[1],val[2]});
        stack<int> s;
        vector<bool > vis(V,false);
        topo(g,s,0,vis);
        d[0]=0;

        while(!s.empty())
        {
            int ver=s.top();
            s.pop();
            
            for(auto &val:g[ver])
            {
                int child=val.first,wt=val.second;
                if(d[child]>d[ver]+wt)
                    d[child]=d[ver]+wt;
            }
        }
        for(int i=0;i<V;i++)
            if(d[i]==INT_MAX)
                d[i]=-1;
        return d;
    }