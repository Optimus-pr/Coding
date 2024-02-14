//here 2 robots are placed at 2 corners of first row and we need to find the max path that can be formed by those 2 robots if both robots enter the same cell then 1 will pick all the cherry from that box 


int rec(int i,int j1,int j2,int n,int m,vector<vector<int>>& a,vector<vector<vector<int> > >& t)
{
    if(j1<0 || j1>=m || j2<0 || j2>=m)
        return INT_MIN;
    
    if(t[i][j1][j2]!=-1)
        return t[i][j1][j2];
    
    if(i==n-1)
    {
        if(j1==j2)
            return a[i][j2];
        return a[i][j1]+a[i][j2];
    }
    
    int mx=-1;
    for(int k=-1;k<=1;k++)
    {
        for(int l=-1;l<=1;l++)
        {
            int val=0;
            if(j1==j2)
                val+=a[i][j2];
            else
                val+=(a[i][j1]+a[i][j2]);
                
            mx=max(mx,val+rec(i+1,j1+k,j2+l,n,m,a,t));
        }
    }
    return t[i][j1][j2]=mx;
}
  
int solve(int n, int m, vector<vector<int>>& a) {
    vector<vector<vector<int> > >t(n,vector<vector<int> > (m,vector<int> (m,-1)));
    return rec(0,0,m-1,n,m,a,t);
}