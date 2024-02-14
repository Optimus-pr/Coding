string multiplyStrings(string s1, string s2) {
       //Your code here
  
   int xr=0;
   if(s1[0]=='-')
   {
       xr=!xr;
       s1=s1.substr(1);
   }
   
  if(s2[0]=='-')
   {
      xr=!xr;
      s2=s2.substr(1);
   }
   int m=s1.size(),n=s2.size();
   reverse(s1.begin(),s1.end());
   reverse(s2.begin(),s2.end());
   
   vector<int> v(m+n,0);
   
   if(s1=="0" || s2=="0")
    return "0";
    
   for(int i=0;i<m;i++)
   {
       for(int j=0;j<n;j++)
       {
           int dig=(s1[i]-'0')*(s2[j]-'0');
           v[i+j]+=dig;
           v[i+j+1]+=(v[i+j])/10;
           v[i+j]=v[i+j]%10;
       }
       
   }
   reverse(v.begin(),v.end());
    int nonZeroPos = 0;
    while (nonZeroPos < v.size() && v[nonZeroPos] == 0) {
        nonZeroPos++;
    }

    if (nonZeroPos == v.size()) {
        return "0";
    }

    stringstream ss;
    
    for (int i = nonZeroPos; i < v.size(); i++) {
        ss << v[i];
    }
    string res;
    if(xr)
    res = '-'+ss.str();
    else 
    res=ss.str();

    return res;
   
}
