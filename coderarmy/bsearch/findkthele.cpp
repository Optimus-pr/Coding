// Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.

// Return the kth positive integer that is missing from this array.

int findKthPositive(vector<int>& arr, int k) {
        int s=0,e=arr.size()-1,mid,ans=arr.size();//here it is init to size as in sorted cases like 1 2 3 4 and k= 6 ans should be 6 but in our case if we have init with somethihng else then we need to add some extra corner case
        while(s<=e)
        {
            mid=(s+e)/2;
            if(arr[mid]-mid-1 >=k)//here arr[i]-i-1 will let you know how many elements are missing before index i
            {
                ans=mid;
                e=mid-1;
            }
            else
                s=mid+1;
        }
        // [2,3,4,7,11], k = 5
        //once we find that index we can do like in this case our ans will point to last index i.e 4 we know that 11-4-1 i.e 6 elements are missing before it so 11-1=10 is the 6th ele missing 11-2=9 is the 5th element missing 
        // i.e 11-(6-K+1) => a[mid]-(a[mid]-mid-1-k+1)
        // =>mid+k => ans+k
        return ans+k;
    }