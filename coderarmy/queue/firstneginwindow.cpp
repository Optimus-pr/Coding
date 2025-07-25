//this question is the combination of queue and sliding window 

vector<int> firstNegInt(vector<int>& arr, int k) {
        // write code here
        queue<int> q;
        vector<int> ans;
        int i=0,j=0,n=arr.size();
        while(j<n)
        {
            if(arr[j]<0)
                q.push(arr[j]);
            if(j-i+1<k)
                j++;
            else
            {
                if(q.size()==0)
                    ans.push_back(0);
                else
                {
                    ans.push_back(q.front());
                    if(q.front()==arr[i])
                        q.pop();
                }
                i++;
                j++;
            }
            
        }
        return ans;
    }