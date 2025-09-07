//find for this in gfg it is same toposort problem but is twisted bit first we need to compare string with nxt string and find the mismatch if we find a missmatch then we need to add edje between those 2 i.e if baa and abcd were there then b->a is added which implies b comes before a in dictionary

//after doing this for all pair we can use toposort instead of letters convert them into numbers and add edjes

string findOrder(vector<string> &words) {
        // code here
        string s="",a,b;
        int n=words.size(),cnt=0;
        vector<int> v(26,0),in(26,0),g[26],ans;
        for(auto &val:words)
            for(auto &info:val){
                if(v[info-'a']==0)
                    cnt++;
                v[info-'a']++;
            }
        
        for(int i=0;i<n-1;i++)
        {
            a=words[i],b=words[i+1];
            int mn=min(a.size(),b.size());
            
            if (a.size() > b.size() && a.substr(0, mn) == b) //this is added because abc ab should return "" because 2nd string len is smaller than first one and is prefix of previous string 
                return "";  // invalid lexicographical order
            
            
            for(int j=0;j<mn;j++)
                if(a[j]!=b[j])
                {
                    g[a[j]-'a'].push_back(b[j]-'a');
                    in[b[j]-'a']++;
                    break;
                }
        }
        queue<int> q;
        for(int i=0;i<26;i++)
            if(v[i] && in[i]==0)
                q.push(i);
        while(!q.empty())
        {
            int ver=q.front();
            q.pop();
            
            s+=(ver+'a');
            
            for(auto &child:g[ver])
                if(--in[child]==0)
                    q.push(child);
        }
        // cout<<s<<endl;
        return s.size()<cnt?"":s;
    }