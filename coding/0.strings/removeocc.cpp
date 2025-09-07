return the string after removing the given occurence of string as many times as possible 

eg:-
Input: s = "daabcbaabcbc", part = "abc"
Output: "dab"

string removeOccurrences(string s, string part) {
        string t;
        int n=part.size(),tn=s.size();
        char ch=part[n-1];

        for(int i=0;i<tn;i++)
        {
            t+=s[i];
            if(s[i]==ch && t.size()>=n)
            {
                if(t.substr(t.size()-n)==part)
                    t.erase(t.size()-n);
            }
        }
        return t;
}