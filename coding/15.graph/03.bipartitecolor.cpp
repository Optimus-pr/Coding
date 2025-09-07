//this code is for only one component i.e if there are multiple connected components then we just need to call them using another function where we call it for each ver if that ver is not colored

bool check(int V, vector<int>adj[])
{
    queue<int> q;
    vector<int> col(V,-1);
    q.push(0);
    col[0]=0;
    
    while(!q.empty())
    {
        int v=q.front();
        q.pop();
        
        for(auto &child:adj[v])
        {
           if(col[child]==-1)
           {
            	q.push(child);
            	col[child]=!col[v];
           }
           else
           {
               if(col[child]==col[v])
                 return false;
           }
        }   
    }
    return true;
}