void transpose(vector<vector<int>>& a, int n) {
        // code here
        for(int i=0;i<n;i++)
	for(int j=0;j<i;j++)
		swap(a[i][j],a[j][i]);
}