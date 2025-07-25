//here we will be give with a matrix which is row and col wise sorted we need to find the kth smallest in that

//init create heap using either first row or first column later on each iteration remove smallest and add the next element from its row or col which ever is stored initially

//here we can't go with conventional way i.e if we have to find kth largest go with min heap if kth smallest then max heap because here 
class Solution {
  public:
    typedef pair<int,pair<int,int> > P;
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        // code here
        vector<P> v;
        int n=matrix.size();
        for(int i=0;i<n;i++)
            v.push_back({matrix[0][i],{0,i}});
        priority_queue<P,vector<P>,greater<P> > q(v.begin(),v.end());
        while(--k)
        {
            int ele=q.top().first,i=q.top().second.first,j=q.top().second.second;
            q.pop();
            if(i+1<n)
            q.push({matrix[i+1][j],{i+1,j}});
        }
        return q.top().first;
    }
};

//the above approach takes 0(n) for creation +2klogn times i.e delete and insert for every element until kth which takes logn for each

//other approaches

//brute force convert 2d array into 1 d array then create heap then remove first k elements from it i.e n2 for converting to 1d then n2 for creation +2klogn2

//