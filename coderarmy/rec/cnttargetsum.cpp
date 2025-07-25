// this logic is for non negative int meaning 0 can also be present 

void cntt(vector<int> &v,int i,int n,int t,int &cnt)
{
    if(i==n)
    {
        if(t==0)
            cnt++;
        return;
    }
   
    cntt(v,i+1,n,t,cnt);
    cntt(v,i+1,n,t-v[i],cnt);
}

//this logic is for +v int the above logic also works but just for FYI
void cntt(vector<int> &v,int i,int n,int t,int &cnt)
{
    if(t==0)
    {
        cnt++;
        return;
    }

    if(t<0 || i==n) //if we place this condi above will it fail think...
        return;
   
    cntt(v,i+1,n,t,cnt);
    cntt(v,i+1,n,t-v[i],cnt);
}
    
  
int perfectSum(vector<int>& arr, int target) {
    int cnt=0;
    cntt(arr,0,arr.size(),target,cnt);
    return cnt;
}

// if we are given the same no can be any no of times then 
void cntt(vector<int> &v,int i,int n,int t,int &cnt)
{
    if(i==n)
    {
        if(t==0)
            cnt++;
        return;
    }
   
    cntt(v,i+1,n,t,cnt);
    cntt(v,i,n,t-v[i],cnt);//here i am not increasing i
}