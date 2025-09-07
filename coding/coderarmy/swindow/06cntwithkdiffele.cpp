//here we need to find the cnt of no of sub which will have exactly k diff elements in them

//we can't go with normal approach here i.e using i and j and move until j<n because
// for eg [1,2,1,2,3], k = 2
// 1,2 cnt=1
// 1,2,1 cnt=2
// 1,2,1,2 cnt=3
// 2,1,2,cnt=4
// 1,2 cnt=5
// but we missed 2,1 here so we are not sure when to increase j and i

// so we have to go with mathematical approach i.e
// if we need exactly(3)=atleast(3)-atleast(4)
//                         or
//                       atmost(3)-atmost(2)

int atmost(vector<int> &nums,int k)
{
    unordered_map<int,int> m;
    int i=0,j=0,cnt=0,n=nums.size();
    while(j<n)
    {
        ++m[nums[j]];

        while(m.size()>k)
        {
            if(--m[nums[i]]==0)
                m.erase(nums[i]);
            i++;
        }
        cnt+=(j-i+1);
        j++;
    }
    return cnt;
}


int atleast(vector<int> &v,int k)
    {
        unordered_map<int,int> m;
        int i=0,j=0,ans=0,n=v.size();

        while(j<n)
        {
            m[v[j]]++;
            
            while(m.size()==k)
            {
                ans+=(n-j);
                if(--m[v[i]]==0)
                    m.erase(v[i]);
                i++;
            }
            j++;
        }
        return ans;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atleast(nums,k)-atleast(nums,k+1);
    }