//here the elements of the 2d array are strictly sorted i.e if we convert the 2d array in 1d we get a sorted array

// we can check if the key comes within the limits of the row if so do bsearch on that row  or imagine 2d array as 1d array and do binary search


bool searchMatrix(vector<vector<int>> &mat, int x) {
        int s=0,e=mat.size()*mat[0].size(),mid,r,c,col=mat[0].size();
        e--;
        
        while(s<=e)
        {
            mid=e-(e-s)/2;
            r=mid/col;
            c=mid%col;
            
            if(mat[r][c]==x)
                return true;
            else if(mat[r][c]<x)
                s++;
            else
                e--;
        }
        return false;
}