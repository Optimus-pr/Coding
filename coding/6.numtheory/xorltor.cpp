#include<iostream>
using namespace std;

int main()
{
	int l,r;

	cin>>l>>r;

	 int xr=0;
        int t=l%4;
        if(t!=0)
        {
            for(;l<(l+4-t);l++)
            xr^=l;
        }
        
        int i=r-((r%4)%3);
        if(i!=r)
        {
            for(;i<=r;i++)
                xr^=i;
        }
        else if(r%4==0)
            xr^=i;
       
        cout<<xr;
}