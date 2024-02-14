 //this is implemented using priority queue i.e min heap

vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
  
    vector<int> dis(V,1e9);
    dis[S]=0;
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
    q.push({0,S});
    
    while(!q.empty())
    {
        auto p=q.top();q.pop();
        int v=p.second;
        int wt=p.first;
        
        for(auto &val:adj[v])
        {
            int cv=val[0],cw=val[1];
            if(wt+cw<dis[cv])
            {
                dis[cv]=wt+cw;
                q.push({dis[cv],cv});
            }
        }
    }
    return dis;
}