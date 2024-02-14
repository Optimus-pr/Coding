//recursion

int rec(vector<vector<int> > &a,int i,int j,vector<vector<int> > &t)
{
    if(i==0 && j==0)
        return a[i][j];
    if(i<0 || j<0)
        return INT_MAX;
    if(t[i][j]!=-1)
        return t[i][j];
    int up=a[i][j]+rec(a,i-1,j,t);
    int left=a[i][j]+rec(a,i,j-1,t);

    return t[i][j]=min(up,left);
}

int minSumPath(vector<vector<int>> &grid) {

   int m=grid.size(),n=grid[0].size();
   vector<vector<int> > t(m,vector<int>(n,-1));
   return rec(grid,m,n,t);

}




//tablulation

int minSumPath(vector<vector<int>> &a) {

   int m=a.size(),n=a[0].size();
   vector<vector<int> > t(m,vector<int>(n,0));

   for(int i=0;i<m;i++)
   {
       for(int j=0;j<n;j++)
       {
           if(i==0 && j==0)
            t[i][j]=a[i][j];
           else
           {
               int left=INT_MAX;
               int up=INT_MAX;
               if(i>0)
                up=a[i][j]+t[i-1][j];
               if(j>0)
                left=a[i][j]+t[i][j-1];
                t[i][j]=min(left,up);
           }
       }
   }
   return t[m-1][n-1];
   
}

//space optimised

int minSumPath(vector<vector<int>> &a) {

   int m=a.size(),n=a[0].size();
   vector<int> prev(n,0);

   for(int i=0;i<m;i++)
   {
       vector<int> cur(n,0); 
       for(int j=0;j<n;j++)
       {
           if(i==0 && j==0)
            cur[j]=a[i][j];
           else
           {
               int left=INT_MAX;
               int up=INT_MAX;
               if(i>0)
                up=a[i][j]+prev[j];
               if(j>0)
                left=a[i][j]+cur[j-1];
                cur[j]=min(left,up);
           }
       }
       prev=cur;
   }
   return prev[n-1];
   
}