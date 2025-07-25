//here if we pass t by ref then pop_back is necessary if not then there is no need for that
void subseq(vector<int> &v,int i,int n,vector<vector<int> > &ans,vector<int> &t)
    {
        if(i==n)
        {
            ans.push_back(t);
            return;
        }

        subseq(v,i+1,n,ans,t);
        t.push_back(v[i]);
        subseq(v,i+1,n,ans,t);
        t.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > ans;
        vector<int> t;

        subseq(nums,0,nums.size(),ans,t);
        return ans;
    }