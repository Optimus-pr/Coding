//we need to find the shortest distance from (0,0) to (X,Y) if we observe carefull this problem is nothing but shortest distance in undirected unweighted graph
// here we are using seperate level matrix instead we can do in another method
int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        queue<pair<int,int> > q;
        q.push({0,0});
        
        vector<pair<int,int> > p={{0,1},{1,0},{-1,0},{0,-1}};
        vector<vector<int> > level(N,vector<int> (M,-1));
        if(A[0][0]==0 || (X>=N && Y>=M))
            return -1;
        if(X==0 && Y==0)
            return 0;
        level[0][0]=0;
        int x,y,nx,ny;
        
        while(!q.empty())
        {
            x=q.front().first,y=q.front().second;
            q.pop();
            
            for(auto &val:p)
            {
                nx=x+val.first,ny=y+val.second;
                if(nx<0 || ny<0 || nx>=N || ny>=M || A[nx][ny]==0 || level[nx][ny]!=-1)
                    continue;
                q.push({nx,ny});
                level[nx][ny]=level[x][y]+1;
                if(level[X][Y]!=-1)
                    return level[X][Y];
            }
        }
        return level[X][Y];
    }


//in the above method we were using level matrix as both to keep track of level and vis matrix but if we remove that we can keep track of level with some variable but inorder to keep track of vis we can directly modify the given matrix after visiting the node make it as 0

space complexity of this approach is o(min(n,m))
int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        queue<pair<int,int> > q;
        q.push({0,0});
        
        vector<pair<int,int> > p={{0,1},{1,0},{-1,0},{0,-1}};
       
        if(A[0][0]==0 || (X>=N && Y>=M))
            return -1;
        if(X==0 && Y==0)
            return 0;
        
        int x,y,nx,ny,step=0,n;
        
        while(!q.empty())
        {
            n=q.size();//considering the fact that only 1 level pairs will be there in queue in any instance
   
            while(n--)
            {
                x=q.front().first,y=q.front().second;
                q.pop();
                for(auto &val:p)
                {
                    nx=x+val.first,ny=y+val.second;
                    if(nx<0 || ny<0 || nx>=N || ny>=M || A[nx][ ny]==0)
                        continue;
                    if(nx==X && ny==Y)
                        return step+1;
                    q.push({nx,ny});
                    A[nx][ny]=0;
                }
            }
            step++;            
        }
        return -1;
    }