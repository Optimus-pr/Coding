//will return the shortest path from s to n 

vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        
        vector<pair<int,int> > g[n+1];
        
        for(auto &val:edges)
        {
            int x=val[0],y=val[1],wt=val[2];
            g[x].push_back({y,wt});
            g[y].push_back({x,wt});
        }
        
        vector<int> p(n+1);
        vector<int> dis(n,1e6);
        
        for(int i=1;i<=n;i++)
            p[i]=i;
            
        priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
        q.push({0,1});
       
        
        while(!q.empty())
        {
            int ver=q.top().second,wt=q.top().first;
            q.pop();
            for(auto &val:g[ver])
            {
                int cv=val.first,cw=val.second;
                
                if(wt+cw<dis[cv])
                {
                    dis[cv]=wt+cw;
                    q.push({dis[cv],cv});
                    p[cv]=ver;               
                }
            }
        }
        
        vector<int> ans;
        if(dis[n]==1e6)return {-1};
        while(n!=p[n])
        {
            ans.push_back(n);
            n=p[n];
        }
       
        return ans;
        
        
    }