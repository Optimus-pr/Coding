//here we will be give a string and we should return the first non repeating char found so far if there is none then return # instead
// eg abbad
//    aaa#d

string Solution::solve(string s) {
    queue<char> q;
    vector<int> v(26,0);
    string ans="";
    int n=s.size();
    for(int i=0;i<n;i++)
    {
        int t=v[s[i]-'a']++;
        if(t==0)
            q.push(s[i]);
        if(v[q.front()-'a']==1)
            ans+=q.front();
        else
        {
            while(q.size() && v[q.front()-'a']!=1)
                q.pop();
            if(q.size()==0)
                ans+='#';
            else
                ans+=q.front();
        }
    }
    return ans;
}