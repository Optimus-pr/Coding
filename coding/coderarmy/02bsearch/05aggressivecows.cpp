// https://www.geeksforgeeks.org/problems/aggressive-cows/1
// we will be given with some stalls and our job is to maximize the min dis between the cows tied to the stall we need to place k jobs like this 


int aggressiveCows(vector<int> &v, int k) {
        sort(v.begin(),v.end());
        int s=1,n=v.size(),e=v[n-1]-v[0],mid,ans,cnt,stall;
        while(s<=e)
        {
            mid=s+(e-s)/2,stall=v[0],cnt=1;
            //checking if all the cows can be placed in the stall
            for(int i=1;i<n;i++)//since first is placed in stall0 we are starting from 1
            {
                if(v[i]-stall>=mid)
                {
                    cnt++;
                    stall=v[i];
                }
            }
            if(cnt<k)//this implies we were unable to tie all the cows-> distance was too much
                e=mid-1;
            else
            {
                ans=mid;
                s=mid+1;
            }
        }
        return ans;
}