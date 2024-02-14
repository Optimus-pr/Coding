//this is same as cnting number of islands but the shape of islands must be unique so simply use a set and put the coordinates by subtracting the least value with all of the remaining value finally the size of the set will be the result 

class Solution {
  public:
    
    void dfs(int i,int j,int m,int n, vector<vector<int> > &vis,vector<vector<int>>& grid,vector<pair<int,int> > &ans,int x,int y)
    {
        if(i<0 || j<0 || i>=m || j>=n || vis[i][j]==1 || grid[i][j]==0)
            return;
            
        vis[i][j]=1;
        
        ans.push_back({i-x,j-y});
        
        dfs(i+1,j,m,n,vis,grid,ans,x,y);
        dfs(i-1,j,m,n,vis,grid,ans,x,y);
        dfs(i,j+1,m,n,vis,grid,ans,x,y);
        dfs(i,j-1,m,n,vis,grid,ans,x,y);
           
        
    }
    
  
    int countDistinctIslands(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int> > vis(m,vector<int>(n,0));
        vector<pair<int,int> > ans;
        set<vector<pair<int,int> > > res;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(vis[i][j]==0 && grid[i][j]==1)
                {
                    ans.clear();
                    dfs(i,j,m,n,vis,grid,ans,i,j);
                    res.insert(ans);
                }
            }
        }
        
        return res.size();
    }
};