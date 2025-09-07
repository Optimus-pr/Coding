bool isValid(int x,int y,int m,int n)
    {
        if(x<0 || y<0 || x>=m || y>=n)
            return false;
        return true;
    }
    
    int helpaterp(vector<vector<int>> h) {
        // code here
        queue<pair<int,int> > q;
        vector<pair<int,int> > v={{0,1},{1,0},{0,-1},{-1,0}};
        int r=h.size(),c=h[0].size();
        
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                if(h[i][j]==2)
                    q.push({i,j});
        if(q.size()==0)
            return 0;
        
        while(!q.empty())
        {
            int n=q.size(),x,y,nx,ny;
            timer++;
            
            while(n--)
            {
                x=q.front().first,y=q.front().second;
                q.pop();
                for(auto &val:v)
                {
                    nx=val.first+x,ny=val.second+y;
                    if(isValid(nx,ny,r,c) && h[nx][ny]==1)
                    {
                        q.push({nx,ny});
                        h[nx][ny]=2;
                    }
                }
            }
        }
        
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                if(h[i][j]==1)
                    return -1;
        return timer-1;//here we are sub -1 becuase the last patient cannot spread the disease to anyone else but the timer had included even his time also so
        
    }