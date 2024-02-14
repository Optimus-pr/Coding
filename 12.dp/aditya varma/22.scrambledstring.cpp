
 
    unordered_map<string,bool> m;
    
    bool isScramble(string a,string b)
    {
        
        if(a==b)
            return true;
       
        string key=a+' '+b;
        
        
        if(m.find(key)!=m.end())
            return m[key];
        
        int n=a.size();
        bool flag=false;
        for(int i=1;i<n;i++)
        {
            if( (isScramble(a.substr(0,i) ,b.substr(0,i) ) && isScramble(a.substr(i,n-i) ,b.substr(i,n-i)))
            || (isScramble(a.substr(0,i) ,b.substr(n-i,i) ) && isScramble(a.substr(i,n-i) ,b.substr(0,n-i))))
             {
                 flag=true;
                 break;
             }
        }
       m[key]=flag;
        return flag;
    }
    