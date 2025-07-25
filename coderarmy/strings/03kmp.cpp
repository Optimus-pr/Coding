//if we are told to check if the patter exists where the string is rotated then we can just add the text 1 time to text and search in that for the patter

void fun(vector<int> &v,int n,string &s)
    {
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
                if(i==0)
                    j++;
                else
                    i=v[i-1];
            }
        }
    }
    
    //remeber we won't take i backwards i.e where we find the issue
    vector<int> search(string& p, string& t) {
        // code here
        vector<int> ans;
        int n=p.size(),m=t.size();
        vector<int> v(n,0);
        fun(v,n,p);
        int i=0,j=0;
        while(i<m)
        {
            if(t[i]==p[j])
            {
                i++;
                j++;
                if(j==n)
                    ans.push_back(i-j);
            }
            else
            {
                if(j!=0)
                    j=v[j-1];
                else
                    i++;
            }
        }
        return ans;
    }