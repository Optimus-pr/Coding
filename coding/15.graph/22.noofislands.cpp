//this is an online query problem i.e here operations are queuries initially we have a n*m matrix all filled with zeroes later for each operation we get x and y so we mark that as visited and 1 in the graph and increase cnt++ implies we got 1 island more that what we had now for each island check in 4 directin if there are any other island if so Union those 2 islands and cnt-- later push cnt to ans indicating that after making the particular x,y as island we got cnt no.of islands which are not connected 

const static int N=1e5;
    
int parent[N],size[N];

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
    
    if(a!=b)
    {
        if(size[a]<size[b])
            swap(a,b);
        size[a]+=size[b];
        parent[b]=parent[a];
    }
}
  
vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
    // code here
    vector<int> ans;
    vector<vector<int> > g(n,vector<int>(m,0));
    vector<int> vis(n*m,0);
    vector<pair<int,int> > move={{0,1},{0,-1},{1,0},{-1,0}};
    
    for(int i=0;i<n*m;i++)
        make(i);
        
    
    int cnt=0;
    
    for(auto &val:operators)
    {
        int x=val[0],y=val[1],z=x*m+y;
        g[x][y]=1;
        if(vis[z]==0)
        {
            cnt++;
            vis[z]=1;
            for(auto &mv:move)
            {
                int nx=x+mv.first,ny=y+mv.second,nz=nx*m+ny;
                if(nx<0 || ny<0 || nx>=n || ny>=m )continue;
                if(g[nx][ny] && (find(nz)!=find(z)) )
                {
                    Union(z,nz);
                    cnt--;
                }
            }
        }
        ans.push_back(cnt);
    }
    return ans;
}