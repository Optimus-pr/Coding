//tarjans algorigthm


//this is similar to bridge but in bridge we find out the edje upon removal created disconnected component but here we see the verticies which creates them at first you can think like this is same as bridge only as if we find bridge then the 2 end connected to the edge will be articulation point but that doesn't hold true always i.e
// 1--2--3--4
//    |     |
//    |_____|

// here 1-2 forms a bridge so 1 and 2 are articulation point is false as 1  is not articulation point so you can try to imporvise this only by saying if the vertex of the bridge has only one child then neglect it but we will get caught in the eg imagine 2 diamonds topconnected to bottom here there are no bridge but the center nodes is articuation point 

// here in the above graph 1 will be articulationPoint which is not so we need to exclude root from this logic so add if(parent[v]!=-1) before checking if dis[ver]<=low[child]

1--2--3
|
|__4__5
//so for root we may impovise that by saying if they have more than 1 child it will be arti but if this was a cycle then this won't hold good so we need to check the no of child which are unvisisted so when cycle is present 1 will have only 1 child so it won't be arti

void dfs(int ver,int par,int cnt,vector<int> g[],vector<int> &vis,vector<int> &dis,vector<int> &low,vector<int> &ans)
    {
        dis[ver]=low[ver]=cnt;
        vis[ver]=1;
        int childd=0;
        for(auto &child:g[ver])
        {
            if(child==par)
                continue;
            else if(vis[child])
            {
                low[ver]=min(dis[child],low[ver]);
            }
            else
            {
                childd++;//remember this logic also to cnt no of unvisited child 
                cnt++;
                dfs(child,ver,cnt,g,vis,dis,low,ans);
                low[ver]=min(low[ver],low[child]);
                if(par!=-1 && dis[ver]<=low[child])//this condition should be checked only for verticies other than root  = was not there in bridge because if we remove edge from 1-2 and 1<1 => there is cycle from 2 to 1 which i have to shown here so that holds good but here 1-2 we remove the vertex 1 so 1<1 doesn't makes sense we need 1<0 to that to be false
                    ans[ver]=1;
            }
        }
        if(childd>1 && par==-1)  
            ans[ver]=1;
    }
    
    vector<int> articulationPoints(int n, vector<int> g[]) {
        // Code here
        vector<int> vis(n,0),dis(n,0),low(n,0),anss;        int cnt=0,flag=0;
        vector<bool> ans(n,false);
        //here we are keeping vector of bool instead of bridge approach because 3--4--5 if we consider this graph the vertex 4 will be inserted twice i am not sure if the eg is right but in case of the edge in bridge the edge will be inserted only once but here there is chance of duplication so better mark that in a vectore and then which ever are marked true they are the ones
        dfs(0,-1,cnt,g,vis,dis,low,ans);

        for(int i=0;i<n;i++)
            if(ans[i]){
                flag=1;
                anss.push_back(i);
            }
        if(flag==0)
            return {-1};
        return anss;

    }