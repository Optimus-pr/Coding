//if a graph is euler circuit then it will have euler path but vice versa is not true
//euler path - each and every edge should be traversed only once
//euler circuit- it should be euler path and starting and ending vertex should be same 

//real time usage-> for kasa collection if he travels as less as possible is good as it save petrol for him

void dfs(int v,vector<int> g[],vector<int> &vis)
    {
        vis[v]=1;
        for(auto &child:g[v])
        {
           if(vis[child])
                continue;
            dfs(child,g,vis); 
        }
    }
    
    //note the condition b is checked via dfs in fun()
    bool isCircuit(vector<int> &in,int n)
    {
        //for the graph to be circuit 
        //a) all the nodes should have even degree if the graph is undirected else indegree of node should be equal to outdegree of the node for all the nodes
        //b) all the non zero degree nodes should be connected
        //c) in case of directed graph all non zero degree nodes should have indegree ==outdegree
        for(int i=0;i<n;i++)
            if(in[i]%2==1)
                return 0;
        return 1;
    }
    
    bool isPath(vector<int> &in,int n)
    {
        //for the graph to be circuit 
        //a) all the nodes should have even degree or exactly 2 nodes can have odd degree
        //b) all the non zero degree nodes should be connected
        //c) if the graph is euler path with exactly 2 odd degree nodes then that can be made into circuit by adding a edge between them 

        int cnt=0;
        for(int i=0;i<n;i++)
            if(in[i]%2==1)
                cnt++;
        if(cnt==0 || cnt==2)
            return 1;
        return 0;
    }
    
    int fun(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V,0),in(V,0);
        for(int i=0;i<V;i++)
            for(auto &val:adj[i])
                in[val]++;
        
        dfs(0,adj,vis);
        
        for(int i=0;i<V;i++)
            if(in[i]!=0 && vis[i]==0)// checking condi a stated above
                return 0;
        
        if(isCircuit(in,V))
            return 2;
        else if(isPath(in,V))
            return 1;
        return 0;
    }