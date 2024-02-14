string reverseWords(string S) 
{ 
    // code here 
    int len=S.size();
    string s="";
    int r,i;
    for(i=len-1;i>=0;i--)
    {
        if(S[i]=='.')
        {
            r=len-i;
            len=i-1;
            s.append(S.substr(i+1,r));
            s.append(".");
        }
    }
 
    s.append(S.substr(0,len+1));
    return s;
} 