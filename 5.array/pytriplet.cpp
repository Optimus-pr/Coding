bool checkTriplet(int a[], int n) {
	sort(a,a+n);
	// code here
	for(int i=n-1;i>=0;i--)
	{
	    int l=0,r=i-1;
	    int num=a[i]*a[i];
	    while(l<=r)
	    {
	        int sum=a[l]*a[l]+a[r]*a[r];
	        if(sum==num)
	            return true;
	        else if(sum<num)
	            l++;
	        else
	            r--;
	    }
	}
	return false;
}