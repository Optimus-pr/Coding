#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a,b,ans=0;
	cin>>a>>b;

	//south-east
	ans+=min(8-a,8-b);

	//south-west
	ans+=min(8-a,b-1);

	//north-east
	ans+=min(a-1,8-b);

	//north-west
	ans+=min(a-1,b-1);

	cout<<ans;
	return 0;

}