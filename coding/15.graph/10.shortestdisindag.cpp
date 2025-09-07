void topo(stack<int> &s,vector<int> &vis,vector<pair<int,int> > adj[],int v)
{
    vis[v]=1;
    for(auto &val:adj[v])
    {
        int child=val.first,wt=val.second;
        if(vis[child]==0)
           topo(s,vis,adj,child);
    }
    s.push(v);
}


vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
   // code here
   vector<pair<int,int> > adj[N];
   
   for(int i=0;i<M;i++)
   {
       int x=edges[i][0];
       int y=edges[i][1];
       int wt=edges[i][2];
       
       adj[x].push_back({y,wt});
   }
   
   stack<int> s;
   vector<int> vis(N,0);
   
   for(int i=0;i<N;i++)
   {
       if(!vis[i])
           topo(s,vis,adj,i);
   }
   
   vector<int> dis(N,1e6);
   dis[0]=0;
   
   while(!s.empty())
   {
       int v=s.top();
       s.pop();
       
       for(auto &val:adj[v])
       {
           int child=val.first,wt=val.second;
           if(dis[v]+wt<dis[child])
               dis[child]=dis[v]+wt;
       }
   }
   
   for(int i=0;i<N;i++)
   {
       if(dis[i]==1e6)
           dis[i]=-1;
   }
   return dis;
}
