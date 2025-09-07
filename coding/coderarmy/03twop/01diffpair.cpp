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

//here if we go via 2sum apprach i.e sort and then start and end when end-start> diff in order to make diff less we need to either decrease end value or inc start value so we can't decide what to do in this case so better start s and e nxt to each other from start so that when we need more diff we can just inc e and when less is required inc s

int Solution::solve(vector<int> &A, int B) {
      int i=0,j=1;
      if(B<0)//to simplify our logic
        B*=-1;
    sort(A.begin(),A.end());
      while(j<n)
      {
        if(a[j]-a[i]==B)
            return 1;
        else if(a[j]-a[i]>B)
            i++;
        else
            j++;
        if(i==j)//this is done because in some case i and j may be equal and we want 2 diff elem to find diff not the same one so do j++ or else when i++ happens there is no check for i<n so memory issue 
            j++;
      }
    return 0;
}