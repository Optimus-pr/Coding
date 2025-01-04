
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> triplet(int n, vector<int> &arr) {
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++) {
        //remove duplicates:
        if (i != 0 && arr[i] == arr[i - 1]) continue;

        //moving 2 pointers:
        int j = i + 1;
        int k = n - 1;
        while (j < k) {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum < 0) {
                j++;
            }
            else if (sum > 0) {
                k--;
            }
            else {
                vector<int> temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp);
                j++;
                k--;
                //skip the duplicates:
                while (j < k && arr[j] == arr[j - 1]) j++;
                while (j < k && arr[k] == arr[k + 1]) k--;
            }
        }
    }
    return ans;
}


int countTriplets(vector<int> &arr, int target) {
        int ans=0,n=arr.size();
        for(int i=0;i<n;i++)
        {
            int j=i+1,k=n-1;
            while(j<k)
            {
                int sum=arr[i]+arr[j]+arr[k];
                if(sum==target){
                  int e1=arr[j],e2=arr[k],c1=0,c2=0;
                  while(j<=k && arr[j]==e1)
                  {
                      c1++;
                      j++;
                  }
                  while(j<=k && arr[k]==e2)
                  {
                      c2++;
                      k--;
                  }
                  if(e1==e2)
                    ans+=(c1*(c1-1))/2;
                  else
                    ans+=c1*c2;
                    
                }
                else if(sum<target)
                    j++;
                else
                    k--;
            }
        }
        return ans;
    }

int main()
{
    vector<int> arr = { -1, 0, 1, 2, -1, -4};
    int n = arr.size();
    vector<vector<int>> ans = triplet(n, arr);
    for (auto it : ans) {
        cout << "[";
        for (auto i : it) {
            cout << i << " ";
        }
        cout << "] ";
    }
    cout << "\n";
    return 0;
}