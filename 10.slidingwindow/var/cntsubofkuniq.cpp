 int solve(string s,int k)
{
    int i=0,j=0,cnt=0,n=s.size(),flag=1,ans=0;
    int a[26]={0};
    
    while(j<n)
    {
        if(flag && ++a[s[j]-97]==1)
            cnt++;
        if(cnt<k)
        {
            j++;
            flag=1;
        }
        else if(cnt==k)
        {
            ans+=n-j;
            if(--a[s[i]-97]==0)
                cnt--;
            i++;
            flag=0;
        }
    }
    return ans;
}

long long int substrCount (string s, int k) {
   return solve(s,k)-solve(s,k+1);
}