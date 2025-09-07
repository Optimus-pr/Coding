#include<bits/stdc++.h>
using namespace std;

int main()
{
	string a,b;
	cin>>a>>b;

	int i=a.size()-1,j=b.size()-1;

	while(i>=0 && j>=0)
	{
		if(a[i]==b[j])
		{
			i--;j--;
		}
		else
			i--;
	}
	if(j<0)
		cout<<"1";
	else
		cout<<"0";
	return 0;

}