int countWays(int n,int k)
{
   vector<int> dp(n+1,0);
   long long mod=1e9+7;
   dp[0]=1;
   
   for(int i=1;i<=n;i++)
   {
       for(int j=1;j<=k;j++)
       {
           if(i-j>=0)
           dp[i]=(dp[i]%mod+dp[i-j]%mod)%mod;
       }
   }
   return dp[n]%mod;
}

//optimized
int count(int n,int k)
{
    dp[0]=dp[1]=1;

    for(int i=2;i<=k;i++)
        dp[i]=2*dp[i-1];
    for(int i=k+1;i<=n;i++)
        dp[i]=2*dp[i-1]-dp[i-k-1];
    return dp[n];
}


int count(int n,int k)
{
    if(n<0)
        return 0;
    if(n==0)
        return 1;
    int ans=0;
    for(int i=1;i<=k;i++)
        ans+=count(n-i);
    return ans;
}

//the above 3 methods are used to find the count if order matters i.e 1 2 1 and 1 1 2 ared considered different 


//but if order doesn't matters then if step size is 1 or 2 

int count(int n)
{
    return ceil(n/2)+1;
}

or 

int count(int n)
{
    dp[0]=dp[1]=1;

    for(int i=2;i<n;i++)
    {
        if(i%2==0)
            dp[i]=dp[i-1]+1;
        else
            dp[i]=dp[i-1];
    }
}
