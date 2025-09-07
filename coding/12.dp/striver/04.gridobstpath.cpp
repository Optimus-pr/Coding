//this problem is same as previous one but here we will be given with a grid and we need to find the number of path from s to e -1 in the grid means obstacle else no obs
//note:we can only travel in left or down direction


int rec(int a,int b,vector<int> grid)
{
    if(a==0 && b==0)
        return 1;

    if(a<0 || b<0)
        return 0;

    if(grid[a][b]==-1)
        return 0;

    if(t[a][b]!=-1)
        return t[a][b];
   
    int left=rec(a-1,b,grid);
    
    int up=rec(a,b-1,grid);

    return t[a][b]=up+left;
}

int NumberOfPath(int a, int b,vector<int> grid)
{
    //code here
    vector<vector<int> > t(a,vector<int>(b,0));
    
    t[0][0]=1;
    
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<b;j++)
        {
            if(grid[i][j]==-1)
                t[i][j]=0;
            else if(i==0 && j==0)
                t[i][j]=1;
            else
            {
                int ans1=0,ans2=0;
                if(i>0)
                    ans1=t[i-1][j];
                if(j>0)
                    ans2=t[i][j-1];
                t[i][j]=ans1+ans2;
            }
        }
    }
    return t[a-1][b-1];
}

//wherever we use previous row and column consept in dp we can space optimise it from 2d array to 1d array i.e

int NumberOfPath(int a, int b)
{
    //code here
    vector<int> prev(b,0);
    
    for(int i=0;i<a;i++)
    {
        vector<int> cur(b,0);
        for(int j=0;j<b;j++)
        {
            if(grid[i][j]==-1)
                cur[j]=0;
            else if(i==0 && j==0)
                cur[j]=1;
            else
            {
                int ans1=0,ans2=0;
                if(i>0)
                    ans1=prev[j];
                if(j>0)
                    ans2=cur[j-1];
                cur[j]=ans1+ans2;
            }
        }
        prev=cur;
    }
    return prev[b-1];
}


//the above approach is just to illustrate how to use dp but the same can be solved using combination