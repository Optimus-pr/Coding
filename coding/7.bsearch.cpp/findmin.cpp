//find min in rotated array

int findMin(vector<int>& v) {
        int s=0,e=v.size()-1,ans;
        if(v[s]<=v[e])
            return v[s];
        while(s<=e)
        {
            int mid=(s+e)/2;
            if(v[mid]>=v[0])
                s=mid+1;
            else
            {
                ans=v[mid];
                e=mid-1;
            }
        }
        return ans;
    }