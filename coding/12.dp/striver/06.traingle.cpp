//here we need to return the lowest cost path from (0,0) to last row and at each time one can visit

int rec(vector<vector<int>>& a,int i,int j,int n,vector<vector<int>>& t)
{
	if(i==n-1)
		return a[i][j];
	if(t[i][j]!=-1)
		return t[i][j];
	int ans1=a[i][j]+rec(a,i+1,j,n,t);
	int ans2=a[i][j]+rec(a,i+1,j+1,n,t);

	return t[i][j]=min(ans1,ans2);
}

int minimumPathSum(vector<vector<int>>& triangle, int n){
	// Write your code here.
	vector<vector<int>> t(n+1,vector<int> (n+1,-1));
	return rec(triangle,0,0,n,t);
}


//tabulation

int minimumPathSum(vector<vector<int>>& a, int n){
	// Write your code here.
	vector<vector<int>> t(n,vector<int> (n,0));
	
	for(int i=0;i<n;i++)
		t[n-1][i]=a[n-1][i];

	for(int i=n-2;i>=0;i--)
	{
		for(int j=i;j>=0;j--)
		{
			int ans1=a[i][j]+t[i+1][j];
			int ans2=a[i][j]+t[i+1][j+1];
			t[i][j]=min(ans1,ans2);
		}
	}
	return t[0][0];
}