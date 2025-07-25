//There are a total of N tasks, labeled from 0 to N-1. Some tasks may have prerequisites, for example to do task 0 you have to first complete task 1, which is expressed as a pair: [0, 1]
Given the total number of tasks N and a list of P prerequisite pairs, find if it is possible to finish all tasks.

bool isPossible(int N, int P, vector<pair<int, int> >& p) {
        // Code here
        vector<int> g[N];
        vector<int> ans;
        vector<int> v(N,0);
        for(auto &val:p){
            g[val.second].push_back(val.first);
            v[val.first]++;
        }
        queue<int> q;
        for(int i=0;i<N;i++)
            if(v[i]==0)
                q.push(i);
        
        while(!q.empty())
        {
            int ver=q.front();
            ans.push_back(ver);
            q.pop();
            
            for(auto &child:g[ver])
            {
                if(--v[child]==0)
                    q.push(child);
            }
        }
        return N==ans.size();
    }