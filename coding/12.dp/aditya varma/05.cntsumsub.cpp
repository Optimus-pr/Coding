//in the subsetsum problem if || is replaced by + then we get the number of count of subsets with required sum

bool isSubsetSum(vector<int>arr, int sum){
    
    int n=arr.size();
    //here if 0 is a part of the set then we get {},{0} as the subset but initially if we fill the first col from 1's then this doesn't hold good so we must just initialize t[0][0] as 1 rest all zeroes and start the inner loop from 0 insread of 1
    vector<vector<int>> t(n+1, vector<int>(sum+1, 0));
    
    t[0][0]=1;
    
    for(int i=1;i<n+1;i++)
    {
        for(int j=0;j<sum+1;j++)
        {
            if(arr[i-1]<=j)
                t[i][j]=t[i-1][j-arr[i-1]]+t[i-1][j];
            else 
                t[i][j]=t[i-1][j];
        }
    }
    return t[n][sum];
}