vector<double> getMedian(vector<int> &a) {
        // code here
    vector<double> ans;
    int n=a.size();
        priority_queue<int> max;
        priority_queue<int,vector<int>,greater<int> > min;
        ans.push_back(a[0]);//here in order to add extra check if max.size()==0 then insert in it within loop i have inserted here only to eliminate extra check in loop
        max.push(a[0]);
        
        for(int i=1;i<n;i++)
        {
            int mx=max.size(),mn=min.size();
            if(mx==mn)
            {
                if(max.top()>a[i]){
                    max.push(a[i]);
                    ans.push_back(max.top());
                }
                else{
                    min.push(a[i]);
                    ans.push_back(min.top());
                }
            }
            else if(mx>mn)
            {
                if(max.top()<a[i])
                    min.push(a[i]);
                else
                {
                    max.push(a[i]);
                    min.push(max.top());
                    max.pop();
                }
                ans.push_back((max.top()+min.top())/2.0);
            }
            else
            {
                if(max.top()>a[i])
                    max.push(a[i]);
                else
                {
                    min.push(a[i]);
                    max.push(min.top());
                    min.pop();
                }
                ans.push_back((max.top()+min.top())/2.0);
            }
        }
        return ans;
    }