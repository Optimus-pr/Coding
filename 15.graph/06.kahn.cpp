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