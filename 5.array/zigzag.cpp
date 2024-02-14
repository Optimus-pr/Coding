void zigZag(int a[], int n) {
        // code here
        for(int i=0;i<n-1;i++)
        {
            if(i%2==0)
            {
                if(a[i]>a[i+1])
                    swap(a[i],a[i+1]);
            }
            else
                if(a[i]<a[i+1])
                    swap(a[i],a[i+1]);
        }
    }