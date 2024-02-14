// used to find the number of ways to reach from starting of the grid to end of the grid

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	int N=n+m- 2;//total number of rights and downs
	int r=m - 1;//u can also take n-1 we are choosing rights or downs in this case i.e - - - in 2x3 matrix  we can take total 3 moves of which 2 is right and 1 is down so either we can choose which is down or which 2 is right. 
	double res = 1;

	for(int i=1;i<=r;i++)
		res = res * (N-r+i)/i;
	
	return (int)res;

}