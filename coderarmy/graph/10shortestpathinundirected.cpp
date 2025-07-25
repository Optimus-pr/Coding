//here we are told to find the shortest path to all the nodes of the graph from the source which we need to store in a graph and return it

vector<int> shortestPath(vector<vector<int>>& g, int src) {
        // code here
        int n=g.size();
        vector<int> d(n,-1),vis(n,0),p(n,-1);
        
        queue<int> q;
        q.push(src);
        d[src]=0;
        vis[src]=1;
        
        while(!q.empty())
        {
            int v=q.front();
            q.pop();
            
            for(auto &child:g[v])
                if(vis[child]==0 ){
                    // p[child]=v;
                    d[child]=d[v]+1;
                    vis[child]=1;
                    q.push(child);
                }
        }
//here the commented code is added to capture the shortest path from a given src to dest and return that path for that just while updating the distance we need to update the parent of the child and later backtrace the parent vector till -1
        
        // int des=5;
        // vector<int> ans;
        // ans.push_back(des);
        // while(p[des]!=-1)
        // {
        //     ans.push_back(p[des]);
        //     des=p[des];
        // }
        // reverse(ans.begin(),ans.end());
        
        // for(auto &val:ans)
        //     cout<<val<<" ";
        // cout<<endl;
        return d;
            
    }