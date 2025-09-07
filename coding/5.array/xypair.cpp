 //this will return the count of number of pairs such that x^y >y^x given array x and y
//sort array y and keep track of cy i.e count of y for numbers less than 5 it will be helpful,if x==0 then there can not be any y such that x^y>y^x so return 0 if x == 1 then return cy[0] else ans+=cy[0]+cy[1] ,find upper bound of x we get an index for all element above that index x^y>y^x satisfies so add n-ub but there are some exceptions i.e when x=2 y=3,4 doesn't satisfy that,but is is already added in n-ub so we need to sub these counts and another exception is for x=3 y=2 satisfies which is not added in count so add cy[2] if x==3

 int count(int x,int * y,int n,int * cy)
    {
        if(x==0)return 0;
        if(x==1)return cy[0];
        int ans=0;
        int ub=upper_bound(y,y+n,x)-y;
        
        if(ub!=-1)
            ans=n-ub;
        
        ans+=(cy[0]+cy[1]);
        if(x==2)
            ans-=(cy[3]+cy[4]);
        if(x==3)
            ans+=cy[2];
        return ans;
    }
    
    long long countPairs(int X[], int Y[], int M, int N)
    {
       //Your code here
       long long ans=0;
       int cy[5]={0};
       for(int i=0;i<N;i++)
        if(Y[i]<5)
            cy[Y[i]]++;
        sort(Y,Y+N);
       
       for(int i=0;i<M;i++)
       {
           ans+=count(X[i],Y,N,cy);
       }
       return ans;
    }