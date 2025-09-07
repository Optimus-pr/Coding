//You are given a graph with n vertices and m edges.

//You can remove one edge from anywhere and add that edge between any two vertices in one operation.

//Find the minimum number of operations that will be required to make the graph connected.

//we know that we need least n-1 edges to connect n nodes but we can't simply return n-1 as we should check for edges which will lead to cycles and remove that edge and put that in empty spaces i.e find the cnt of edges forming cycle if it is >= n-1 then return n-1 else return -1 as we don't have enough edges to form a connected graph

const static int v=1e6;
int parent[v],size[v];

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
        parent[b]=a;
    }
}

int Solve(int n, vector<vector<int>>& edge) {
    // code here
    for(int i=0;i<n;i++)
        make(i);
    int cnt=0,ct=0;
    for(auto &val:edge)
    {
        int a=val[0],b=val[1];
        if(find(a)==find(b))
            cnt++;
        else
            Union(a,b);
    }
    
    for(int i=0;i<n;i++)
        if(parent[i]==i)
            ct++;
            
    if(cnt>=ct-1)
        return ct-1;
    else 
        return -1;
    
}