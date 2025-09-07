//normal fails for 50 25 30 the known approach will return yes for k=1 but for k=1 the expected answer is No so go for this approach

string isKSortedArray(int arr[], int n, int k)
    {
        int count=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >pq;
        for(int i=0;i<n;i++){
            pq.push({arr[i],i});
        }
        bool f=true;
        while(!pq.empty()){
            pair<int,int> s= pq.top();
            pq.pop();
            if(abs(s.second-count)>k){
                f=false;
                break;
            }
            count++;
        }
        string ans="No";
        if(f) ans="Yes";
        return ans;
            
    }