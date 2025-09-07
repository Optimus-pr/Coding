#include<unordered_map>
#include<iostream>

using namespace std;

int main()
{
	int n,sum;
	cin>>n>>sum;

	int a[n];

	for(int i=0;i<n;i++)
		cin>>a[i];

	unordered_map<int,int> u;//use unordered_set

	for(int i=0;i<n;i++)
	{
		
		if(u.find(sum-a[i])!=u.end())
		{
			cout<<(u[sum-a[i]])<<" "<<a[i]<<endl;
			break;
		}
		else
			u[a[i]]=i;
	}

}


// the above approach for cnting fails as if we have 1 1 1 1 1 and target as 2 then above will give 4 pairs where the ans is 10
int countPairs(vector<int> &arr, int target) {
        int cnt=0;
        unordered_map<int,int> m;
        for(auto &val:arr)
        {
            if(m.find(target-val)!=m.end())
                cnt+=m[target-val];
            m[val]++;
        }
        return cnt;
    }



//count subarrays with sum as k
 int countSubarrays(vector<int> &arr, int k) {
        map<int, int>mp;
        mp[0] = 1;
        int preSum = 0, cnt = 0;
        for(int i=0; i<arr.size(); i++)
        {
            preSum += arr[i];
            int remove = preSum - k;
            cnt += mp[remove];
            mp[preSum] += 1;
        }
        return cnt;
 }