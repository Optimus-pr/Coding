pair<int,int> smatch(string x,string y)
{
    int n=x.size(),m=y.size();
    
    for(int i=0;i<=n-m+1;i++)
    {
        int j=0,flag=0;
        while(j<m && x[i+j]==y[j])
        {
            flag=1;j++;
        }
        if(flag)   
        return {i,j};
        return {-1,-1};
    }
    return {-1,-1};
}
    
string longestCommonPrefix (string arr[], int N)
{
    // your code here
    sort(arr,arr+N);
    int mcnt=999,cnt;
    if(N==1)
    return arr[0];
    
    for(int i=1;i<N;i++)
    {
        auto p=smatch(arr[i],arr[0]);
        if(p.first!=0)
            return "-1";
        cnt=p.second-p.first+1;
        //cout<<cnt<<" ";
        if(cnt<mcnt)
            mcnt=cnt;
    }
    if(mcnt==999)
        return "-1";
    return arr[0].substr(0,mcnt-1);
}