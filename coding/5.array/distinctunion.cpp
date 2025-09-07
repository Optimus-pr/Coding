//approach 1: we can use map and store the key values inside the array to get the union

//approach 2: we can use set and store the same insider array


//approach 3:two pointer approach ,we can use v.back() to know the recently added element inside vector.


vector<int> findUnion(int a1[], int a2[], int n, int m)
    {
        vector<int> v;
        int i=0,j=0,temp=-999;
        while(i<n && j<m)
        {
            if(a1[i]<a2[j])
            {
                if(v.size()==0 || v.back()!=a1[i])
                 v.push_back(a1[i]);
                i++;
            }
            else if(a1[i]>a2[j])
            {
                if(v.size()==0|| v.back()!=a2[j])
                v.push_back(a2[j]);
                j++; 
            }
            else
            {
                if(v.size()==0 || v.back()!=a1[i])
                v.push_back(a1[i]);
                i++;
                j++;
            }
        }
        for(;i<n;i++)
        {
            if(v.back()!=a1[i])
            v.push_back(a1[i]);
        }

        for(;j<m;j++)
        {
            if(v.back()!=a2[j])
             v.push_back(a2[j]);
        }
       
        return v;
    }