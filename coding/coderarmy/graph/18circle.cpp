// Given an array arr of lowercase strings, determine if the strings can be chained together to form a circle.
// A string X can be chained together with another string Y if the last character of X is the same as the first character of Y. If every string of the array can be chained with exactly two strings of the array(one with the first character and the second with the last character of the string), it will form a circle.

// For example, for the array arr[] = {"for", "geek", "rig", "kaf"} the answer will be Yes as the given strings can be chained as "for", "rig", "geek" and "kaf"

// this question is somewhere beating around the bush is what i feel near euler circuit but not exactly ..... this means hamiltonian circuit euler was worried about only edges likewise viceversa in case of hamiltonian
// here if we observe there is no need for in between char of the string as only first and last is used 

void dfs(int v,vector<int> g[],vector<int> &vis)
    {
        vis[v]=1;
        for(auto &child:g[v])
        {
            if(vis[child])
                continue;
            dfs(child,g,vis);
        }
    }
  
    int isCircle(vector<string> &arr) {
        // code here
        int cnt=0,a,b;
        unordered_map<char,int> m;
        for(auto &val:arr){
            if(m.find(val[0])==m.end())
                m[val[0]]=cnt++;
            if(m.find(val[val.size()-1])==m.end())
                m[val[val.size()-1]]=cnt++;
        }

        vector<int> g[cnt],in(cnt,0),out(cnt,0),vis(cnt,0);
        for(auto &val:arr){
            a=m[val[0]],b=m[val[val.size()-1]];
            g[a].push_back(b);
            in[b]++;
            out[a]++;
        }
        
        dfs(0,g,vis);// to check disconnected component
   
        for(int i=0;i<cnt;i++)
        {
            if(vis[i]==0)
            {
                if(in[i] || out[i])
                    return false;
            }
            else if(in[i]!=out[i])
                return false;
            
        }
        return true;
    }