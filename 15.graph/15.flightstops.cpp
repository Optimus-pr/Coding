//here we need to find the distance from src to dest such that it can stop atmost on K nodes i.e we need to use dijkstra's but instead of sorting via distance we need to sort via stops 

int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
    // Code here
    vector<pair<int,int> > g[n];
    
    for(auto &val:flights)
    {
        int x=val[0],y=val[1],wt=val[2];
        g[x].push_back({y,wt});
    }
    
    priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > >,greater<pair<int,pair<int,int> > > > q;
    vector<int> dis(n,1e5);
    dis[src]=0;
    
    q.push({0,{src,0}});
    //stops,node,cost
    
    while(!q.empty())
    {
        int stop=q.top().first;
        int v=q.top().second.first;
        int cost=q.top().second.second;
        q.pop();
        
        if(stop>K)continue;
        
        for(auto &val:g[v])
        {
            int cv=val.first,wt=val.second;
            if(cost+wt<dis[cv])
            {
                dis[cv]=cost+wt;
                q.push({stop+1,{cv,dis[cv]}});
            }
        }
    }
    if(dis[dst]==1e5)
        return -1;
    return dis[dst];
}