// find pair such that the diff is B
int Solution::solve(vector<int> &A, int B) {
       unordered_map<int,int> s;
    for(auto &val:A)
        s[val]++;
    for(auto &val:A)
    {
        if(B==0)
        {
            if(s[val]>1)
            return 1;
        }
        else if(s[val-B] || s[val+B])
            return 1;
    }
    return 0;
}