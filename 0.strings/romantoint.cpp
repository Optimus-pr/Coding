int romanToDecimal(string &str) {
        // code here
    unordered_map<char,int> m;
    m.insert({'I',1});
    m.insert({'X',10});
    m.insert({'L',50});
    m.insert({'C',100});
    m.insert({'D',500});
    m.insert({'M',1000});
    m.insert({'V',5});
    int num=0,n=str.size();
    for(int i=0;i<n;)
    {
        if(i==n-1||m[str[i]]>=m[str[i+1]])
        {
            num+=m[str[i]];
            i++;
        }
        else
        {
            num+=m[str[i+1]]-m[str[i]];
            i+=2;
        }
    }
    return num;
}




string convertToRoman(int n) {
        // code here
      
    vector<pair<string,int> > v={{"M",1000},{"CM",900},{"D",500},{"CD",400},{"C",100},{"XC",90},{"L",50},{"XL",40},{"X",10},{"IX",9},{"V",5},{"IV",4},{"I",1}};
     
    string s="";
    for(auto &val:v)
    {
        string a=val.first;
        int b=val.second;
        
        int N=n/b;
       
        for(int i=0;i<N;i++)
         s.append(a);
        n=n%b;
        
        
    }
     return s;
    
}