// v = [5, 6, 7, 1, 2, 3, 4]
// the min element will always lie in the unsorted array because if we see here in the rotated case before 1 all will be greater so when mid is before 1 5<7 will be true but the min will be present after mid+1 here we are storing ans because when mid is 1 5<1 false ans=1 then e=mid-1 so 5<7 true like wise until s>e happens so the ans stored previsouly will be used later

int findMin(vector<int>& v) {
        int s=0,e=v.size()-1,ans;
        if(v[s]<=v[e])
            return v[s];
        while(s<=e)
        {
            int mid=(s+e)/2;
            if(v[0]<=v[mid])
                s=mid+1;
            else
            {
                ans=v[mid];
                e=mid-1;
            }
        }
        return ans;
    }