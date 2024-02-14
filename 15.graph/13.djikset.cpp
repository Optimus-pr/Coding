//here we use set instead of pq bcause assume in the q we have a pair {10,5} indicating node 5 can be reached by source with dis 10 but later you will find better path to 5 i.e {8,5} so you will insert this inside pq now you will process {8,5} first as it has less distance and later {10,5} but {10,5} is waste as {8,5} is processed before it all the path will be updated to shortest distance so what we can do by using set is we can just remove the {10,5} how we will get to know init dis will be inf later if better dis is got i.e 10 we will update from next we will check if dis is inf if so just update if not we will remove the pair{10,5} from the set and later do the processing

vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
       
        
        vector<int> dis(V,1e9);
        dis[S]=0;
        set<pair<int,int> > st;
        st.insert({0,S});
        
        while(!st.empty())
        {
            auto p=*(st.begin());
            int v=p.second;
            int wt=p.first;
            st.erase(st.begin());
            
            for(auto &val:adj[v])
            {
                
                int cv=val[0],cw=val[1];
                
                if(wt+cw<dis[cv])
                {
                    if(dis[cv]!=1e9)
                        st.erase({dis[cv],cv});
                    
                    dis[cv]=wt+cw;
                    st.insert({dis[cv],cv});
                }
            }
        }
        return dis;
    }