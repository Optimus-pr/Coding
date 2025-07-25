//the normal way of detecting cycle in undirected graph won't work here take for eg 4->5->0->1->2->3 is the graph if we start dfs from 0 vertex it will traverse all the way till 3 and come back all of them will have visited tag as 1 now when we start from vertex 4 as it is not visited when the control reaches vertex 0 we see that 0 is vis and 0 is not parent of 5 so cycle exists so return true

bool isDetected(vector<int> arr[],vector<bool> &vis,vector<bool> &pvis,int ver)
    {
        vis[ver]=1;
        pvis[ver]=1;
        
        for(auto &child:arr[ver])
        {
            if(pvis[child])
                return 1;
            if(vis[child])
                continue;
            if(isDetected(arr,vis,pvis,child))
                return 1;
        }
        pvis[ver]=0;
        return 0;
    }


    //here even this code works fine the need for introducing vis and pvis vector is consider and eg if 

// 0->1
// 1->2 3
// 2->4
// 3->4
// 4->5

// here init 0 1 2 4 5 will be traversed while returning it does pvis=0 to dead end ver so 0 1 3 4 5 will work but we know that from first traversal that after vertex 4 there is no cycle but still we are computing the same in the second traversal also so we introduce the second vector i.e if pathvis =0 and vis =1 => there is no cycle in that path and no need to do computation further as the previous runs have already confirmed that
    bool isDetected(vector<int> arr[],vector<bool> &pvis,int ver)
    {
        pvis[ver]=1;
        for(auto &child:arr[ver])
        {
            if(pvis[child])
                return 1;
            
            if(isDetected(arr,pvis,child))
                return 1;
        }
        pvis[ver]=0;
        return 0;
    }
  
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<bool> vis(V,0);
        vector<bool> pvis(V,0);
        
        vector<int> edge[V];
        for(auto &val:edges)
            edge[val[0]].push_back(val[1]);
            
        for(int i=0;i<V;i++)
        if(vis[i]==0 && isDetected(edge,vis,pvis,i))
            return true;
        return false;
    }


    //the above method is DFS version of finding cycle 



// the other approach of  cycle detection is using toposort using ******Kahn's only******* we can't do topo sort using dfs as it won't return the correct result


    // do topo sort using kahn's and then check if ans.size()==v 