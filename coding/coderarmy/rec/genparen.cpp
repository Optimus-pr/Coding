void gen(vector<string> &v,int o,int c,string &s)
    {
        if(o==0 && c==0)
        {
            v.push_back(s);
            return;
        }
        if(o>0)
        {
            s.push_back('(');
            gen(v,o-1,c,s);
            s.pop_back();
        } 
        if(o<c)
        {
            s.push_back(')');
            gen(v,o,c-1,s);
            s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s="";
        gen(ans,n,n,s);
        return ans;
    }