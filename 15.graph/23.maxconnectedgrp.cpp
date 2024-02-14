public:
    const static int sz=250000;
    int parent[sz];
    int size[sz];
    
    void make(int i)
    {
        parent[i]=i;
        size[i]=1;
    }
    
    int find(int i)
    {
        if(parent[i]==i)
            return i;
            
        return parent[i]=find(parent[i]);
    }
    
    void Union(int a,int b)
    {
        a=find(a);
        b=find(b);
        
        if(find(a)!=find(b))
        {
            if(size[a]<size[b])
                swap(a,b);
            size[a]+=size[b];
            parent[b]=a;
        }
    }

    int largestIsland(vector<vector<int>>& a) 
    {
        // Your code goes here.
        int m=a.size(),n=a[0].size();
       
        vector<pair<int,int> > mov={{1,0},{-1,0},{0,1},{0,-1}};
        
       for(int i=0;i<n*n;i++)
            make(i);
            
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(a[i][j]==0)continue;
                int z=i*n+j;
                
                for(auto &val:mov)
                {
                    int nx=i+val.first,ny=j+val.second,nz=nx*n+ny;
                    if(nx<0 || ny<0 || nx>=m ||ny>=n)
                        continue;
                    if(a[nx][ny])
                        Union(z,nz);
                }
            }
        }
        
        int mans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                unordered_set<int> s;
                int ans=0;
                if(a[i][j]==0)
                {
                    for(auto &val:mov)
                    {
                        int nx=val.first,ny=val.second,nz=nx*n+ny;
                        if(nx<0 || ny<0 || nx>=m ||ny>=n)
                            continue;
                        if(a[nx][ny]==0)continue;
                        s.insert(find(nz));
                    }
                    
                    for(auto &val:s)
                        ans+=size[val];
                    mans=max(ans+1,mans);
                }
            }
        }
        
        for(int i=0;i<m*n;i++)
            mans=max(mans,size[i]);
        return mans;
    }