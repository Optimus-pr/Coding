//method 1
//here we are not using any priority_queue and all simply we are keeping dis and xplored vector o(V2) time because for each vertex we are finding the shortest 
// and coming to space it takes o(v) size
vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<pair<int,int> > g[V];
        for(auto &val:edges)
            g[val[0]].push_back({val[1],val[2]});
        vector<int> dis(V,INT_MAX),x(V,0);
        dis[src]=0;
        int cnt=V;
        
        while(cnt--)
        {
            int ver=-1,value=INT_MAX;
            //here we find the shortest unexplored dis from dis vector
            for(int i=0;i<V;i++)
            {
                if(!x[i] && value>dis[i])
                {
                    ver=i;
                    value=dis[i];
                }
            }
            //once we get that ver we make it as explored
            x[ver]=1;
            //then we relax the edjes
            for(auto &val:g[ver])
            {
                int child=val.first,wt=val.second;
                if(dis[ver]+wt<dis[child])
                    dis[child]=dis[ver]+wt;
            }
        }
        return dis;
    }


//method 2
//using priority queue this will take o(loge) for searching 

//this approach takes 0(v+e) space because in worst case the given graph can be complete graph

//coming to time there are e edges that can go into prio queue so eloge time if complete graph then e=v2 so elogv2=>elogv times
vector<int> f(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<pair<int,int> > g[V];
        priority_queue<pair<int,int>,vector<pair<int,int> > ,greater<pair<int,int> > > q;
        for(auto &val:edges)
            g[val[0]].push_back({val[1],val[2]});
        vector<int> dis(V,INT_MAX),x(V,0);
        dis[src]=0;
        q.push({dis[src],src});
        
        while(q.size())
        {
            int ver=q.top().second,wt=q.top().first;
            q.pop();
            
            if(x[ver])
                continue;
            
            x[ver]=1;
            
            for(auto &val:g[ver])
            {
                int child=val.first,wt=val.second;
                if(dis[ver]+wt<dis[child]){
                    dis[child]=dis[ver]+wt;
                    q.push({dis[child],child});
                }
            }
        }
        return dis;
    }

//IMP_NOTE

    // if the given graph is dense graph then first approach will be best because o(v) space and o(v2) time
    //     but 2nd will give o(v+e) space and o(v2loge)
    // if the given graph is sparse graph then second approach will be useful

    // but in real life the graph will be sparce so we use priority_queu approach

//dijikstra algo doesn't work for -ve weights it gives wrong ans what is -ve wt 

    // say if you go from a to b you have to pay 10 rs but if you go from a to c then will pay you 10 rs so represent that as -10 because their route will get crowded their gdp will increase something like this you can imagine