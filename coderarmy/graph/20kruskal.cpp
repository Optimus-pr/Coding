//why we use priority queue here we can also do sorting of vertex also right?

// no because if prio queue is implemented using bottom up apprach then it takes o(n) time for creation so
	int parent[1000];
	int size[1000];
	
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
	        parent[b]=a;
	        size[a]+=size[b];
	    }
	}
	
	typedef pair<int,pair<int,int> > pp;
	
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        
        for(int i=0;i<V;i++)
            make(i);
        
       	vector<pp> v;
        
        for (int i = 0; i < V; i++) {
        for (auto &edge : adj[i]) {
            v.push_back({edge[1], {i, edge[0]}});
        }
    }
        priority_queue<pp,vector<pp>,greater<pp> > s(v.begin(),v.end())//o(n) creation of heap via stl
        
        int cost=0,a,b;
        
        while(!s.empty())//inside this we can also keep a counter if V-1 edjes are added then exit out of this
        {
            auto val=s.top();
            s.pop();
            
            a=find(val.second.first);
	        b=find(val.second.second);
	        
	        
	        if(a!=b)
	        {
	            Union(a,b);
	            cost+=val.first;
	        }
        }
        return cost;
        
    }