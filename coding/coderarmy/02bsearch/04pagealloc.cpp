// here we need to distribute the pages present in nums among m students such that each student atleast get pages and the
// pages should be alloted inn contiguos manner and the diff of pages got by all the students should be min

//note there is one more problem called painter partition problem i.e also same as this and also ship packages even i.e same 

// whenever we are told to distibute something in continguous manner among some n things and asked to return the minimum wt of ships or min pages or min time required to paint the wall this can be used

//here the nums need not to be sorted

int findPages(vector<int> &nums, int m)  {
        int n=nums.size(),mx=0,sum=0,mid;
        if(n<m)
            return -1;
        for(auto &val:nums)
        {
            mx=max(mx,val);
            sum+=val;
        }
        int s=mx,e=sum,ans=-1;//we can also start s from 1 and e from intmax but instead we can start the same with max pages and e with sum
        while(s<=e)
        {
            mid=(s+e)/2;//mid implies we can allot these many pages in max to a person
            int cnt=1,pages=0;
            for(int i=0;i<n;i++)
            {
                pages+=nums[i];
                if(pages>mid)//if adding the nums[i] exceeds mid then the nums[i] should be given to cnt+1 person and pages will be nums[i]
                {
                    cnt++;
                    pages=nums[i];
                }
            }
            // if no of person is > cnt that many persons are needed to share that mid but we can't stuff some pages in other person so we need to move s to mid+1 without storing it ni ans

            // whereas say if the no of person required is less than m say 1 => mid is so big that all the pages can be alloted to single person (which doesn't follow the rule but we can understand that if everypages follows unders single person then that can be shared among differenet people also so store that in ans and reduce mid)
            if(cnt<=m)
            {
                ans=mid;
                e=mid-1;
            }
            else
                s=mid+1;
        }
        return ans;
    }

    // 12 34 67 90 has to be distributed between 2 then

    // 12          34,67,90 =>191
    // 12,34       67,90    =>157
    // 12,34,67    90       =>113

    // here we need to return minimum of maximum