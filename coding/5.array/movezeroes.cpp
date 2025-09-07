void moveZeroes(vector<int>& a) {
    
    int i=0,j=0,n=a.size();

    while(j<n)
    {
        if(a[j]!=0)
        {
            swap(a[i],a[j]);
            i++;
        }
        j++;
    }
}