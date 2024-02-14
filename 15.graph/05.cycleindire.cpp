bool check(vector<int> adj[], vector<int> &vis, vector<int> &pvis,int v)
{
    vis[v]=1;
    pvis[v]=1;
 
    for(auto &child:adj[v])
    {
        if(vis[child]==0)
        {
            vis[child]=1;
            pvis[child]=1;
           if(check(adj,vis,pvis,child))
                return true;
        }
        if(pvis[child])
            return true;
       
    }
    pvis[v]=0;
    return false;
   
}
    
bool isCyclic(int V, vector<int> adj[]) {
    vector<int> vis(V,0);
    vector<int> pvis(V,0);
    
    for(int i=0;i<V;i++)
    {
        if(vis[i]==0)
            if(check(adj,vis,pvis,i))
                return true;
    }
    return false;
}