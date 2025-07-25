void per(vector<int> &v,int ind,int n,vector<vector<int> > &ans)
{
    if(ind==n)
    {
        ans.push_back(v);
        return;
    }

    for(int i=ind;i<n;i++)
    {
        swap(v[i],v[ind]);
        per(v,ind+1,n,ans);
        swap(v[i],v[ind]);
    }
}

vector<vector<int>> permute(vector<int>& v) {
    vector<vector<int> > ans;
    per(v,0,v.size(),ans);
    return ans;
}