//this code is to find shortest path from source to all nodes given wts are 1 between each edje here we can simply use bfs technique to traverse and compute dis from the source to that node

vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
      // code here
     vector<int> adj[N];
     
     for(int i=0;i<M;i++)
     {
         int x=edges[i][0];
         int y=edges[i][1];
         adj[x].push_back(y);
         adj[y].push_back(x);
     }
     
     queue<int> q;
     q.push(src);
     
     vector<int> dis(N,1000);
     dis[src]=0;
     
     while(!q.empty())
     {
         int v=q.front();
         q.pop();
         
       
         
         for(auto &val:adj[v])
         {
             
             if(dis[v]+1<dis[val])
             {
                 dis[val]=dis[v]+1;
                 q.push(val);
             }
                
         }
     }
     
     for(int i=0;i<N;i++)
     {
         if(dis[i]==1000)
             dis[i]=-1;
     }
     return dis;
}