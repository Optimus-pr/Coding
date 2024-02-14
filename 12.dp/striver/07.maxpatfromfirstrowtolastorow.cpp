 
    int rec(int i,int j,int N,vector<vector<int>> &a,vector<vector<int>> &t)
    {
        if(j<0 || j>=N)
            return INT_MIN;
        if(i==0)
            return a[i][j];
        if(t[i][j]!=-1)
            return t[i][j];
            
        int x=a[i][j]+rec(i-1,j-1,N,a,t);
        int y=a[i][j]+rec(i-1,j,N,a,t);
        int z=a[i][j]+rec(i-1,j+1,N,a,t);
        
        
        
        return t[i][j]=max(x,max(y,z));
    }

    int maximumPath(int N, vector<vector<int>> a)
    {
        vector<vector<int> > t(N,vector<int> (N,-1));
        int mx=-1;
        
        for(int i=0;i<N;i++)
        {
            mx=max(mx,rec(N-1,i,N,a,t));
        }
       
        return mx;
    }