bool iscycle(int N,int P, vector<pair<int, int> >& v) {
    // Code here
    vector<int> in(N,0);
    vector<int> g[N];
    vector<int> ans;
    queue<int> q;
    
    for(int i=0;i<P;i++)
    {
       int x=v[i].second,y=v[i].first;
       g[x].push_back(y);
    }
    
    for(int i=0;i<P;i++)
    {
        int y=v[i].first;
        in[y]++;
    }
    
    for(int i=0;i<N;i++)
        if(in[i]==0)
            q.push(i);
            
   while(!q.empty())
   {
       int t=q.front();
       q.pop();
       ans.push_back(t);
       for(auto &val:g[t])
        if(--in[val]==0)
            q.push(val);
   }
   if(ans.size()==N)//if there is cycle at one point there will be nothing in queue so ans size will not be equal to the number of vertex
        return true;
   else 
        return false;
}