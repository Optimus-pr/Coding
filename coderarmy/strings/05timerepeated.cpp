 // Given two strings a and b, return the minimum number of times you should repeat string a so that string b is a substring of it. If it is impossible for b to be a substring of a after repeating it, return -1.

 void lps(vector<int> &v,int n,string &s)
    {
        int i=0,j=1;
        while(j<n)
        {
            if(s[i]==s[j])
            {
                v[j]=i+1;
                i++;j++;
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

    bool kmp(string &t,string &p)
    {
        int ps=p.size(),ts=t.size();
        vector<int> v(ps,0);
        lps(v,ps,p);
        int i=0,j=0;
        while(i<ts)
        {
            if(t[i]==p[j]){
                i++;j++;
                if(j==ps)
                    return true;
            }
            else
            {
                if(j==0)
                    i++;
                else
                    j=v[j-1];
            }
        }
        return false;
    }

    int repeatedStringMatch(string a, string b) {
        if(a==b)
            return 1;
        int cnt=1,bs=b.size();
        string t=a;

        while(t.size()<bs)
        {
            t+=a;
            cnt++;
        }
            

        if(kmp(t,b))
            return cnt;
        t+=a;
        if(kmp(t,b))
            return cnt+1;
        return -1;
    }