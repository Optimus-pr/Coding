//number of unique path from starting grid to end if you can go only right and down a and b are rows and columns

int rec(int a,int b)
{
    if(a==0 && b==0)
        return 1;

    if(a<0 || b<0)
        return 0;

    if(t[a][b]!=-1)
        return t[a][b];
   
    int left=rec(a-1,b);
    
    int up=rec(a,b-1);

    return t[a][b]=up+left;
}

int NumberOfPath(int a, int b)
{
    //code here
    vector<vector<int> > t(a,vector<int>(b,0));
    
    t[0][0]=1;
    
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<b;j++)
        {
            if(i==0 && j==0)
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
            if(i==0 && j==0)
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