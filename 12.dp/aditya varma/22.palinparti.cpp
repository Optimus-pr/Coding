
class Solution{
public:
    
    int dp[501][501];
    bool isPalind(string s,int i,int j)
    {
        if(i>=j)return true;
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    
    int pp(string s,int i,int j)
    {
        
        if(i>=j)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(isPalind(s,i,j))
            return 0;
        int mx=INT_MAX;
        for(int k=i;k<j;k++)
        {
            int left,right;
            if(dp[i][k]==-1)
            {
                left=pp(s,i,k);
                dp[i][k]=left;
            }
            else
                left=dp[i][k];
                
             if(dp[k+1][j]==-1)
             {
                 right=pp(s,k+1,j);
                 dp[k+1][j]=right;
             }
            else
                right=dp[k+1][j];
                
            int ans=left+right+1;
            if(ans<mx)
                mx=ans;
        }
        return dp[i][j]=mx; 
    }

    int palindromicPartition(string str)
    {
        
        memset(dp,-1,sizeof(dp));
        return pp(str,0,str.size()-1);
    }
};

