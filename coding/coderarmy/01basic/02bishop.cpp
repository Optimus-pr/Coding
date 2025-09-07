#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a,b,ans=0;
	cin>>a>>b;

	//south-east
	// either it can reach 8th or 8th col which ever it reaches first we need to take that so min
	ans+=min(8-a,8-b);

	//south-west
	// here either 1st col or 8th row whichever reach first 
	ans+=min(8-a,b-1);

	//north-east
	ans+=min(a-1,8-b);

	//north-west
	ans+=min(a-1,b-1);

	cout<<ans;
	return 0;

}