

class Solution{
public:

   
    int dp[101][101];
    int mcm(int *a,int i,int j)
    {
        if(i>=j)
            return 0;
            
        if(dp[i][j]!=-1)
            return dp[i][j];
            
        int mn=INT_MAX;
        
        for(int k=i;k<j;k++)
        {
            int ans=mcm(a,i,k)+mcm(a,k+1,j)+a[i-1]*a[k]*a[j];
            if(ans<mn)
                mn=ans;
        }
        return dp[i][j]=mn;
    }

    int matrixMultiplication(int N, int a[])
    {
        // code here
       
       memset(dp,-1,sizeof(dp));
        int ans=mcm(a,1,N-1);
    }
};


