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


// the below is the kahn approach for finding out topo sort 

    //this is used for toposort here initially indegree of all nodes are computed and the nodes with indegree 0 are pushed into q there after we go on reducing the indegree of verticies conected to the node which was present inside the queue once we get the node with indegree 0(i.e every time we pop from queue that node will have indegree 0) we push them into the ans

vector<int> kahn(queue<int> &q,vector<int> adj[],vector<int>& in)
{
    vector<int> ans;
    while(!q.empty())
    {
        int v=q.front();
        q.pop();
        ans.push_back(v);
        
        for(auto &val:adj[v])
            if(--in[val]==0)
                q.push(val);
    }
    return ans;
}

vector<int> topoSort(int V, vector<int> adj[]) 
{
    // code here
    vector<int> in(V,0);
    queue<int> q;
    
    for(int i=0;i<V;i++)
    {
        for(auto &val:adj[i])
            in[val]++;
    }
    
    for(int i=0;i<V;i++)
        if(in[i]==0)
            q.push(i);
    
   
    vector<int> ans=kahn(q,adj,in);
    return ans;
}