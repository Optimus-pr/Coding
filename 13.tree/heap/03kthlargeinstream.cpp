//here we need to find kth largest in stream
//don't confuse this question with sliding window problem of size k 

vector<int> kthLargest(int k, int arr[], int n) {
    // code here
    vector<int> ans;
    priority_queue<int,vector<int>,greater<int> > q;
    
    for(int i=0;i<k-1;i++)
        ans.push_back(-1);
    for(int i=0;i<k;i++)
        q.push(arr[i]);
    ans.push_back(q.top());
    for(int i=k;i<n;i++)
    {
        
        if(arr[i]>q.top())
        {
            q.pop();
            q.push(arr[i]);
        }
        ans.push_back(q.top());
    }
    return ans;
}

// eg for input 2 3 1 4 0 6

// ans should be -1 -1 -1 1 1 2
// and not       -1 -1 -1 1 0 2

// i.e when we have 4 element in min heap if an element comes which is smaller that s.top() adding that to the heap doesn't make sense as the result won't change instead we will get wrong answer i.e when we have 1 2 3 4 if 0 comes 4th largest will be 1 only not 0 but if 6 comes then we need to pop min element as 1 2 3 4 6    4th largest is 2 so ... 