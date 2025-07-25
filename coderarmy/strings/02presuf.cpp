int longestPrefixSuffix(string &s) {
        // Your code goes here
        int n=s.size();
        vector<int> v(n,0);
        int i=0,j=1;
        
        while(j<n)
        {
            if(s[i]==s[j])
            {
                v[j]=i+1;
                i++;
                j++;
            }
            else
            {
                if(i==0){
                    v[j]=0;
                    j++;
                }
                else
                    i=v[i-1];
            }
            
        }
        // for(auto &val:v)
        //     cout<<val<<" ";
        // cout<<endl;
        return v[n-1];
    }