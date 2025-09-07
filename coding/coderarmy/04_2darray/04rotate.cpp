//clockwise rotate by 90 deg
void rotate(vector<vector<int>>& v) {
        int n=v.size();
        for(int i=0;i<n;i++)
            for(int j=0;j<i;j++)
                swap(v[i][j],v[j][i]);
        for(int i=0;i<n;i++)
        {
            reverse(v[i].begin(),v[i].end());
        }
    }
// like wise if multiple of 90 is given we can either opt to repeat the same that many number of times
// the same goes for anticlockwise rotation if 90 deg anti then 270 deg clock or else just try some using tranpose reverse blah blah like patter problem
