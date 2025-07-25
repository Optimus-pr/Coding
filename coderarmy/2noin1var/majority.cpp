//element> n/2 given there exist atleast one element as such
int majorityElement(vector<int>& nums) {
       int n=nums.size(),size=n/2,vote=0,ans=INT_MIN;
       for(auto &val:nums)
       {
        if(vote==0 || ans==val)
        {
            vote++;
            ans=val;
        }
        else vote--;
       }
       return ans; 
    }

    // if it is not guranteed that there exists a majority element then we need to add this extra thing
    // for(auto &val:arr)
    //     if(val==ans)
    //         cnt++;
    //     if(cnt>size)
    //         return ans;
    //     else
    //         return -1;