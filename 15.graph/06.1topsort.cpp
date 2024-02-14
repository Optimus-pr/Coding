    //topsort is the linear ordering of verticies such that if there is an edje from i to j the i comes always before j
//note topsort is only for dag i.e directed graphs without cycles

    public:
    //Function to return list containing vertices in Topological order. 
    
    void dfs(int v,vector<int> adj[],vector<int> &vis,stack<int> &s)
    {
        vis[v]=1;
       
        for(auto &child:adj[v])
        {
            if(vis[child]==0)
                dfs(child,adj,vis,s);
           
        }
         s.push(v);//this has to be done after exit vertex not after entering the vertex
    }
    
    vector<int> topoSort(int V, vector<int> adj[]) 
    {
        stack<int> s;
        // code here
        vector<int> vis(V,0);
        for(int i=0;i<V;i++)
            if(vis[i]==0)
                dfs(i,adj,vis,s);
        vector<int> ts;
        while(!s.empty())
        {
            ts.push_back(s.top());
            s.pop();
        }
        return ts;
    }