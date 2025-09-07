class Solution {
public:

    void dfs(vector<vector<int>>& image, int i, int j, int color,int clr)
    {
        int m=image.size(),n=image[0].size();
        if(i<0 || j<0 || i>=m || j>=n || image[i][j]!=clr)
            return;

        image[i][j]=color;

        dfs(image,i+1,j,color,clr);
        dfs(image,i-1,j,color,clr);
        dfs(image,i,j+1,color,clr);
        dfs(image,i,j-1,color,clr);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size(),n=image[0].size(),clr=image[sr][sc];
        if(color==image[sr][sc])
            return image;
            
         dfs(image,sr,sc,color,clr);   
        
        return image;
    }
};