int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        int sum=0;
        for(int i=0;i<n;i++)
            sum+=arr[i];
         if((sum+d)%2!=0)return 0;
        int s1=(sum+d)/2;
       
       
        vector<vector<int> > t(n+1,vector<int>(s1+1,0));
        t[0][0]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=s1;j++)
            {
                if(arr[i-1]<=j)
                    t[i][j]=(t[i-1][j-arr[i-1]]+t[i-1][j])%1000000007;
                else 
                    t[i][j]=t[i-1][j];
            }
        }
        
        return t[n][s1];
       
    }