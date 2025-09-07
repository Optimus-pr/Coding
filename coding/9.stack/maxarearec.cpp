//note first read histoarea then come to this as the consepts are similar only


//here we are given with a binary matrix for which we need to find the max area if we look similarly this problem is similar to the histoarea one only diff is there it was 1d here it is 2d so we need to convert the given 2d matrix into 1d and that can be easily performed i.e take 1st row assume 0 1 1 0 now compute the area for each historgram store the max value now assume 2nd row was 1 1 1 1 => 1 2 2 1 this is got by adding the 2 rows again compute area and store the max value now assume if the 3rd row is 1 1 0 0 then the resulting historgram will be 1 2 0 0 again compute the same and return max area

vector<int> left(vector<int> &v,int n)
{
    vector<int> ans(n,-1);
    stack<int> s;
    for(int i=n-1;i>=0;i--)
    {
        while(!s.empty() && v[s.top()]>v[i])
        {
            ans[s.top()]=i;
            s.pop();
        }
        s.push(i);
    }
    return ans;
}

vector<int> right(vector<int> &v,int n)
{
    vector<int> ans(n,n);
    stack<int> s;
    for(int i=0;i<n;i++)
    {
        while(!s.empty() && v[s.top()]>v[i])
        {
            ans[s.top()]=i;
            s.pop();
        }
        s.push(i);
    }
    return ans;
}

int fun(vector<int>& v) {
    int n=v.size(),mx=0;
    vector<int> l=left(v,n);
    vector<int> r=right(v,n);
    for(int i=0;i<n;i++)
        mx=max((r[i]-l[i]-1) *v[i],mx);
    return mx;
}

int maximalRectangle(vector<vector<char>>& matrix) {
    int m=matrix.size(),n=matrix[0].size(),mx=-1;
    vector<int> v(n,0);
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(matrix[i][j]=='1')
                v[j]+=1;
            else
                v[j]=0;
        }
        mx=max(fun(v),mx);
    }
    return mx;
}