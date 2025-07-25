int minStepToReachTarget(vector<int>& k, vector<int>& t, int n) {
        // Code here
        int sx=k[0]-1,sy=k[1]-1,dx=t[0]-1,dy=t[1]-1,x,y,nx,ny;
        vector<pair<int,int> > v={{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{-2,1},{2,-1},{-2,-1}};
        vector<vector<int> > level(n,vector<int> (n,-1));
        
        queue<pair<int,int> > q;
        q.push({sx,sy});
        level[sx][sy]=0;
        
        while(!q.empty())
        {
            x=q.front().first,y=q.front().second;
            q.pop();
            
            for(auto &val:v)
            {
                nx=x+val.first,ny=y+val.second;
                if(nx<0 || ny<0 || nx>=n || ny>=n || level[nx][ny]!=-1)
                    continue;
                q.push({nx,ny});
                level[nx][ny]=level[x][y]+1;
            }
            if(level[dx][dy]!=-1)
                return level[dx][dy];
        }
        return level[dx][dy];
    }