//this problem finally boils down to find the no of connected components

vector<pair<int,int> > v={{0,1},{0,-1},{1,0},{-1,0},{1,-1},{-1,1},{1,1},{-1,-1}};
    void dfs(vector<vector<char> > &g,vector<vector<int> > &vis,int i,int j,int r,int c)
    {
        if(i<0 || j<0 || i>=r || j>=c || g[i][j]=='W'|| vis[i][j]==1)
            return;
        vis[i][j]=1;
        for(auto &val:v)
            dfs(g,vis,i+val.first,j+val.second,r,c);
    }
  
    int countIslands(vector<vector<char>>& grid) {
        // Code here
        int r=grid.size(),c=grid[0].size(),cnt=0;
        vector<vector<int> > vis(r,vector<int>(c,0));
        
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                if(vis[i][j]==0 && grid[i][j]=='L'){
                    cnt++;
                    dfs(grid,vis,i,j,r,c);
                }
                
        return cnt;
    }