vector<int> spirallyTraverse(vector<vector<int> > m, int rt, int c) 
{
    // code here 
    vector<int> v;
    
    int l=0,r=c-1,t=0,b=rt-1,size1=0,size2=rt*c;
    while(size1<size2)
    {
        for(int i=l;i<=r && size1<size2;i++)
        {
            v.push_back(m[t][i]);size1++;
        }
            
        t++;
        
        for(int i=t;i<=b && size1<size2;i++)
        {
            v.push_back(m[i][r]);size1++;
        }
            
        r--;
        
        for(int i=r;i>=l && size1<size2;i--)
        {
            v.push_back(m[b][i]);size1++;
        }
            
        b--;
        
        for(int i=b;i>=t && size1<size2;i--)
        {
             v.push_back(m[i][l]);size1++;
        }
           
        l++;
            
    }
    return v;
    
}