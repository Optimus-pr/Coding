//safe state means starting from a node every path should end up in a terminal node(i.e outdegree 0) this code is same as cycle detection in directed graph in that for whichever verticies the pvis[] was 0 => those are all safe states so just modifey the code to change that part 

bool check(vector<int> adj[], vector<int> &vis, vector<int> &pvis,vector<int> &vis, vector<int> &issafe,int v)
    {
        vis[v]=1;
        pvis[v]=1;
        
        for(auto &child:adj[v])
        {
            if(vis[child]==0)
            {
                vis[child]=1;
                pvis[child]=1;
               if(check(adj,vis,pvis,child,issafe))
                    return true;
            }
            if(pvis[child])
                return true;
           
        }
        issafe[v]=1;
        pvis[v]=0;
        return false;
       
    }
    
bool isCyclic(int V, vector<int> adj[]) {
    vector<int> vis(V,0);
    vector<int> pvis(V,0);
    vector<int> issafe(V,0);
    
    for(int i=0;i<V;i++)
    {
        if(vis[i]==0)
            dfs(adj,vis,pvis,i,issafe)
                
    }
    return false;
}