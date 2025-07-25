// https://leetcode.com/problems/koko-eating-bananas/

int minEatingSpeed(vector<int>& v, int h) {
       int mx=0,cnt,mid,s=1,e,ans,n=v.size();
        for(auto &val:v)
            mx=max(mx,val);//to optimise we can start s from sum/h but it casues some complexity so better just from 1 anyways as bsearch will take logn complexity
        e=mx;
        while(s<=e)
        {
            mid=e+(s-e)/2,cnt=0;
            for(int i=0;i<n;i++)
                cnt+=(v[i]%mid)?(v[i]/mid)+1:v[i]/mid;
                
            if(cnt<=h)
            {
                ans=mid;
                e=mid-1;
            }
            else
                s=mid+1;
        }
        return ans;
    }