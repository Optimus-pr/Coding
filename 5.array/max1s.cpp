 // Given a binary array arr of size N and an integer M. Find the maximum number of consecutive 1's produced by flipping at most M 0's.



 int findZeroes(int v[], int n, int m) {
        // code here
        int i=0,j=0,cnt=0,mcnt=0;
        
        while(j<n)
        {
            if(v[j]==0)
                cnt++;
            while(cnt>m)
            {
                if(v[i]==0)cnt--;
                i++;
            }
            mcnt=max(mcnt,j-i+1);
            j++;
        }
        return mcnt;
    }  