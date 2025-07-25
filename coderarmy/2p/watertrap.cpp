//without using extra space

int trap(vector<int>& h) {
         int n=h.size(),lmax=0,rmax=0,ans=0,ind=-1,mx=0;
         for(int i=0;i<n;i++)
         {
            if(h[i]>mx)
            {
                mx=h[i];
                ind=i;
            }
         }

         //left part
         for(int i=0;i<ind;i++)
            if(lmax>h[i])
                ans+=lmax-h[i];
            else
                lmax=h[i];

         for(int i=n-1;i>ind;i--)
            if(rmax>h[i])
                ans+=rmax-h[i];
            else
                rmax=h[i];
        return ans;
    }

//using extra space

    int trap(vector<int>& h) {
        int n=h.size();
        vector<int> left(n,0),right(n,0);
        for(int i=1;i<n;i++)
            left[i]=max(left[i-1],h[i-1]);
        for(int i=n-2;i>=0;i--)
            right[i]=max(right[i+1],h[i+1]);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int minht=min(left[i],right[i]);
            if(minht>h[i])
                ans+=minht-h[i];
        }
        return ans;
    }