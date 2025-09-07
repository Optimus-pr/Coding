int maxOnes(int a[], int n)
    {
        // Your code goes here
       int b[n],cnt=0;
       for(int i=0;i<n;i++)
       {
           if(a[i]==0)
            b[i]=1;
            else
            b[i]=-1,cnt++;
       }
       int sum=0,mx=0;
      
        for(int i=0;i<n;i++)
        {
            sum+=b[i];
            mx=max(mx,sum);
            if(sum<0)
                sum=0;
        }
       
        return mx+cnt;
    }