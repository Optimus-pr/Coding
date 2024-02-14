//used to find the number of strongly connected components
// i)this algorithm mainely has 3 phases in the first phase store the order in which the verticies become dead end by performing dfs
// ii)reverse all the edges of the graph
// iii)apply dfs again based on the stack how many times we can execute dfs that many connected components will be present

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void dfs(int v,stack<int> &s,vector<int> &vis, vector<int> g[])
	{
	   vis[v]=1;
	   for(auto &child:g[v])
	   {
	       if(vis[child]==1)continue;
	       dfs(child,s,vis,g);
	   }
	   s.push(v);
	}
	
	void dfs1(int v,vector<int> &vis,vector<int> g[])
	{
	   vis[v]=1;
	   for(auto &child:g[v])
	   {
	       if(vis[child]==1)continue;
	       dfs1(child,vis,g);
	   }
	}
	
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        vector<int> g[V];
        vector<int> g1[V];
        
        vector<int> vis(V,0);
        stack<int> s;
        
        for(int i=0;i<adj.size();i++)
        {
            for(int j=0;j<adj[i].size();j++)
            {
                int u=adj[i][j];
                g[i].push_back(u);
                g1[u].push_back(i);
            }
        }
           
        
        for(int i=0;i<V;i++)
        {
            if(vis[i]==0)
                dfs(i,s,vis,g);
        }
       
        
        int cnt=0;
        
        fill(vis.begin(),vis.end(),0);
        
        while(!s.empty())
        {
            int v=s.top();s.pop();
            
            if(vis[v]==0)
            {
                cnt++;
                //here we can also store the connected components if needed
                dfs1(v,vis,g1);
                

            }
        }
        return cnt;
    }
};


