 //here we have to return the number of ways in which we can reach the desti from the src with least distance


 int countPaths(int n, vector<vector<int>>& roads) {
        // code here
        vector<pair<int,int> > g[n];
        
        for(auto &val:roads)
        {
            int x=val[0],y=val[1],wt=val[2];
            
            g[x].push_back({y,wt});
            g[y].push_back({x,wt});
        }
        
       priority_queue<pair<int,int>,vector<pair<int,int> > ,greater<pair<int,int> > > q;
       q.push({0,0});
       vector<int> dis(n,1e9+1);
       vector<int> ways(n,0);
       ways[0]=1;
       dis[0]=0;
       int mod=(int)1e9+7;
     
       
       while(!q.empty())
       {
           int wt=q.top().first,v=q.top().second;q.pop();
           for(auto &val:g[v])
           {
               int cv=val.first,cw=val.second;
               if(wt+cw<dis[cv])
               {
                   dis[cv]=wt+cw;
                   q.push({dis[cv],cv});
                   ways[cv]=ways[v];//if v has 3 paths then cv should also have 3 paths so assign them
               }
               else if(wt+cw==dis[cv])
                   ways[cv]=(ways[cv]+ways[v])%mod;//ways[cv]+=1 is wrong 
           }
       }
    return (ways[n-1])%mod;