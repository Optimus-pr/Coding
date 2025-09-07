  
int rec(string s,string p,int i,int j,vector<vector<int> > &t)
{
    if(i<0 && j<0)return true;
    if(i<0 && j>=0)return false;
    if(j<0 && i>=0)
    {
        for(int k=0;k<=i;k++)
            if(p[k]!='*')
                return false;
        return true;
    }
    if(t[i][j]!=-1)
        return t[i][j];
    
    if(p[i]=='?'||(s[j]==p[i]))
        return t[i][j]=rec(s,p,i-1,j-1,t);
    if(p[i]=='*')
        return t[i][j]=rec(s,p,i-1,j,t) || rec(s,p,i,j-1,t);
        
    return t[i][j]=false;
}

int wildCard(string p,string s)
{
    int n=p.size(),m=s.size();
    vector<vector<int> > t(n,vector<int> (m,-1));
    return rec(s,p,n-1,m-1,t);
}