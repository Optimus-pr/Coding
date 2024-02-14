 //instead of going for acbca a==a c==c b==b we are going from inside i.e b==b c==c a==a like wise

 string longestPalin (string S) {
        // code here
    int n=S.size(),mx=0;
    string s="";

    //finding odd length substring
    for(int i=0;i<n;i++)
    {
        int l=i,r=i;
        while(l>=0 && r<=n-1 && S[l]==S[r])
        {
            if(r-l+1>mx)
            {
                mx=r-l+1;
                s=S.substr(l,mx);
            }
            l--;r++;
        }
        
    }
    
    //finding even length substring
    for(int i=0;i<n;i++)
    {
        int l=i,r=i+1;
        while(l>=0 && r<=n-1 && S[l]==S[r])
        {
            if(r-l+1>mx)
            {
                mx=r-l+1;
                s=S.substr(l,mx);
            }
            l--;r++;
        }
        
    }
    return s;
}