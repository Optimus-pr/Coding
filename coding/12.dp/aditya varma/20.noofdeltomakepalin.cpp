//this is same as lps but we need to remove the len of the lps with the length of the given string 
//soln is same for min no.of insertion to make the string palindrom

int countMin(string a){
    
    string b=a;
    reverse(b.begin(),b.end());
    int n=a.size();
    int t[n+1][n+1];
    
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0||j==0)
                t[i][j]=0;
        }
    }
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[i-1]==b[j-1])
                t[i][j]=t[i-1][j-1]+1;
            else
                t[i][j]=max(t[i][j-1],t[i-1][j]);
        }
    }
    return n-t[n][n];
}