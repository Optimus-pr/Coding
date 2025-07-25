//hamiltonian path is similar to euler path but there we need to traverse all the edjes but here we need to visit all the vertex there is no standard approach as such brute force is the only solution it takes n! here but if we go throguh normal dp approach it will be n2*2^n ig
//if we know it is hamiltonian path than we can 

bool dfs(int ver,int &cnt,int n,vector<bool> &vis,vector<vector<int> > &g)
    {
        vis[ver]=1;
        cnt++;
        
        if(cnt==n)
            return 1;
            
        for(int i=0;i<g[ver].size();i++)
        {
            if(!vis[g[ver][i]] && dfs(g[ver][i],cnt,n,vis,g))
                return 1;
        }
        vis[ver]=0;
        cnt--;
        return 0;
    }
  
    bool check(int n, int m, vector<vector<int>> v) {
        // code here
        vector<vector<int> > g(n);
        for(int i=0;i<m;i++)
        {
            g[v[i][0]-1].push_back(v[i][1]-1);
            g[v[i][1]-1].push_back(v[i][0]-1);
        }
        int cnt=0;
        vector<bool> vis(n,0);
        for(int i=0;i<n;i++)
        if(dfs(i,cnt,n,vis,g))
            return 1;
        return 0;
    }