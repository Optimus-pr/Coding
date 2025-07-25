//the aim here is to return all the a->b edge which upon removal the graph becomes disconnected 

//the approach is to first do dfs setting each node's discovered and low array to cnt which will incremented each time say 1 2 3 4 are in loop so init 1 2 3 will have (1,1) (2,2) (3,3) (4,4) now when dfs(4) is called it enters 1 which is already visited since 1 is already visisted => the edge is not a bridge update the low of 4 telling that 4 can reach lowest value of 1 upon backtracking check if dis[4]<low[3] i.e 3<1 false now keep on updating the low i.e low[3]=min(low[3],low[4]) i.e since 4 can reach lowest of 1 even 3 can reach lowest of 1  .... if we find any vertex such that dis[ver]<low[child] => that edge is a bridge so add it in answer

// 1---2----3----4---5---6
//          |            |
//          |____________|

// 6->(6,3)
// 5->(5,3)
// 4->(4,3)
// 3->(3,3)
// 2->(2,2)
// 1->(1,1)

//here say if we want to check if edge 5->6 is bridge or not when we remove that there should be edge from 6 to any nodes connected to 5 that can be either 4 or 3 or 2 or 1 . 3 in this case so that's what low means low[6]=3 =>even we remove the edje i can reach you via node having lesser value that you i.e 3 but when it comes to 2->3 if we remove that low[3] is not 1 i.e dis[2]<low[3] so removal causes bridge

void dfs(int ver,int par,int cnt,vector<int> g[],vector<int> &vis,vector<int> &dis,vector<int> &low,vector<vector<int> > &ans)
    {
        dis[ver]=low[ver]=cnt;
        vis[ver]=1;
        for(auto &child:g[ver])
        {
            if(child==par)
                continue;
            else if(vis[child])
            {
                low[ver]=min(low[child],low[ver]);//here we can also do low[ver]=min(low[ver],dis[child]) because this will be used in articulation logic instead of the above one
            }
            else
            {
                cnt++;
                dfs(child,ver,cnt,g,vis,dis,low,ans);
                low[ver]=min(low[ver],low[child]);
                if(dis[ver]<low[child])
                    ans.push_back({ver,child});
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& v) {
        vector<int> g[n],vis(n,0),dis(n,0),low(n,0);
        vector<vector<int> > ans;
        for(auto &val:v){
            g[val[1]].push_back(val[0]);
            g[val[0]].push_back(val[1]);
        }
        int cnt=1;
        dfs(0,-1,cnt,g,vis,dis,low,ans);
        return ans;
    }