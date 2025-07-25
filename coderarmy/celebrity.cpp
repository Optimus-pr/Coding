//given a matrix where v[i][j]=1 => i knows j and v[j][i]=1 means j know i here we need to find the celebrity i.e all of them knows him he doesn't know anyone (except him) we can use for loop and check for that easily but it takes o(n2) but here we need to prove that in o(n) so we can use stacks i.e we know that if we have 4 people say 0 1 2 3 we can take 2 at a time and ask each other if you know the other guy say if 0 knows 1 and 1 doesn't knows 0 => 1 is celebrity  like wise if 1 knows 0 and 0 dosn't know 1 => 0 is celebrity if both knows each other or both doesnt know each other then they are not celebrities
//at the end we are checking again because if the matrix is 0 1 0 , 1 0 0, 1 1 1 at the end we only have 2 but on cross checking we get to know that he is not a celebrity
int celebrity(vector<vector<int> >& mat) {
        // code here
        int n=mat.size();
        stack<int> s;
        for(int i=0;i<n;i++)
            s.push(i);
        while(s.size()>1)
        {
            int a=s.top();s.pop();
            int b=s.top();s.pop();
            
            if(mat[a][b]==1 && mat[b][a]==0)
                s.push(b);
            else if(mat[a][b]==0 && mat[b][a]==1)
                s.push(a);
        }
        if(s.size()==0)
            return -1;
        int ans=s.top(),row=0,col=0;
        for(int i=0;i<n;i++)
        {
            row+=mat[ans][i];
            col+=mat[i][ans];
        }
        return row==1 && col==n?ans:-1;
    }