//the first 2 problem we solved using prefix sum method but here if we do prefix prod then it will lead to overflow error so better not to go via that approach and stick to normal sliding window approach only

int numSubarrayProductLessThanK(vector<int>& nums, int k){
       long long i=0,j=0,n=nums.size(),p=1,ans=0;
       while(j<n)
       {
           p*=nums[j];
           while(p>=k && i<=j)
           {
               p/=nums[i];
               i++;
           }
           ans+=(j-i+1);
           j++;
       }
       return ans;
   }