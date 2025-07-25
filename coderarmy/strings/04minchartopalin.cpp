//minimum char to add front to make the string palindrome
//here we need to return the no of char to be added at front but if what has to be added is asked then the int rep last - char so reverse them and attach in front 
// here we need to insert a dollar in between 2 diff 2 string or else say string is aaa when we add aaaaaa at the end it will return 6 3-6 will be final which is wrong but if aaa#aaa then it will return 3 so 3-3 =0 which is correct
int lps(string s)
    {
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
  
    int minChar(string& s) {
        // Write your code here
        int n=s.size();
        string a=s;
        reverse(s.begin(),s.end());
        s=a+"$"+s;
        return n-lps(s);
        
    }