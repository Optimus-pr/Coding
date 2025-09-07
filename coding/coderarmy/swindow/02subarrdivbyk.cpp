int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        m[0]=1;
        int sum=0,rem,ans=0;
        for(auto &val:nums)
        {
            sum+=val;
            rem=sum%k;
            if(rem<0)//handling -ve rem
                rem+=k;
            if(m.find(rem)!=m.end())
                ans+=m[rem];
            m[rem]++;
        }
        return ans;
}

//here we can obtise the above part bit more that is no need to take unordered map as we know when we do mod with k we get rem from 0 to k-1 only so we can just have a vector of that size

// rem=(sum+k)%k if we do this no need to keep the conditional check if(rem<0) as we are adding k already

// 0 1 2 3 1 4 
// 0 1 3 6 7 11 ->prefix sum

// 0 1 3 6 0 4  -> prefix sum%7 here k is 7, here we can see at 0th ind prefix sum%7 is 0 and at 4th index also prefix sum%7 is 0 => in between 0th and 4th index the sum obtained will be divisible by 7 so insteated of checking sum-k is found previously we have to see rem is found previously


// for -ve no we may have to slightly modify the logic bit if no is -3 the rem with 7 can be -3 also or 4 also 
// because -3=7*0 -3
//         -3=7*-1 + 4
//     so we can just add 7 to -3 to make it to 4 