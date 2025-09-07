//the aim is to find the no of strongly connected components 

//kosaraju algorithm 

//strongly connected commponent -> if subset of the graph is said to be strongly connected then all the vertex will be reached from any other vertex of that component 
// 0<--1      5<--6
// |   |      |   |
// |   |      |   |


// 2-->3->9<--4-->7

// so here if we do dfs 0239 so we cannot find thd components so somehow we have to make sure after 3 it should go to 1 so if reverse all the edges it works like a charm , but now we should take care of the order in which dfs is done i.e first 0123 will be done so one componet later since 5 is not visited if we start from there then 45679 will be considered as a component so total 2 components but here there are 3 component i.e after 0123 we should consider doing 9 and then 4567 so we should find some hack to chose the order of verties so topological sort is the way but here also there is one hack if topo sort is done via kahns algo then for cycle it will detect but it wont give the order but if we go through dfs approach it will return the order of vertieces even if cycle is present so first find topo sort with dfs keep the v in the stack and remove each vertex from the stack and if the v is not visisted then do dfs on the reversed graph and find the connected components in the same


void dfs(int ver,vector<int> g[],stack<int> &s,vector<int> &vis)
    {
        vis[ver]=1;
        for(auto &child:g[ver]){
            if(vis[child])
                continue;
            dfs(child,g,s,vis);
        }
        s.push(ver);
    }
    
    void dfss(int ver,vector<int> g[],vector<int> &vis)
    {
        vis[ver]=1;
        for(auto &child:g[ver])
        {
            if(vis[child])
                continue;
            dfss(child,g,vis);
        }
    }
    
    int kosaraju(vector<vector<int>> &adj) {
        // code here
        int n=adj.size(),cnt=0;
        vector<int> g[n],u[n],vis(n,0);
        for(int i=0;i<n;i++)
            for(auto &val:adj[i]){
                g[i].push_back(val);
                u[val].push_back(i);
            }
        
        stack<int> s;
        for(int i=0;i<n;i++)
            if(vis[i]==0)
                dfs(i,g,s,vis);
                
        for(int i=0;i<n;i++)
            vis[i]=0;
        
        while(!s.empty())
        {
            if(vis[s.top()]==0)
            {
                dfss(s.top(),u,vis);
                cnt++;
            }
            s.pop();
        }
        return cnt;   
    }