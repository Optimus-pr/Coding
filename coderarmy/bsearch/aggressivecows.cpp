// https://www.geeksforgeeks.org/problems/aggressive-cows/1

int aggressiveCows(vector<int> &v, int k) {
        sort(v.begin(),v.end());
        int s=1,n=v.size(),e=v[n-1]-v[0],mid,ans,cnt,stall;
        while(s<=e)
        {
            mid=s+(e-s)/2,stall=v[0],cnt=1;
            for(int i=1;i<n;i++)
            {
                if(v[i]-stall>=mid)
                {
                    cnt++;
                    stall=v[i];
                }
            }
            if(cnt<k)
                e=mid-1;
            else
            {
                ans=mid;
                s=mid+1;
            }
        }
        return ans;
}