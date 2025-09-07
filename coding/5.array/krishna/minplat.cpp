int findPlatform(int a[], int d[], int n)
{
	// Your code here
    int cnt=1,mx=1,i=1,j=0;
    sort(a,a+n);
    sort(d,d+n);
    while(i<n && j<n)
    {
        if(a[i]<=d[j])
        {
            cnt++;
            i++;
            if(cnt>mx)
                mx=cnt;
        }
        else
        {
            cnt--;
            j++;
        }
    }
	return mx;
}