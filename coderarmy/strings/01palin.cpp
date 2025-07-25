//largest palindrome that can be formed from using the given char of the string 

int longestPalindrome(string s) {
        unordered_map<char,int> m;
        bool flag=false;
        for(auto &val:s)
            m[val]++;
        int cnt=0;
        for(auto &val:m)
            if(val.second%2==0)
                cnt+=val.second;
            else
            {
                flag=true;
                cnt+=val.second-1;
            }
        if(flag)
            cnt++;
        return cnt;
}