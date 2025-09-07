//floyd warshal algorithm is used to find all pair shortest path and even detects cycle

void shortest_distance(vector<vector<int>>&matrix){
    // Code here
    int m=matrix.size(),n=matrix[0].size();
    
    for(int k=0;k<m;k++)
    {
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<m;j++)
            {
                matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
            }
        }
    }

    for(int i=0;i<m;i++)
    {
    	if(matrix[i][i]<0)
    		cout<<"there is negative weighted cycle";
    	//floyd warshal only detects negative weighted cycle it won't work for that
    }
  
}