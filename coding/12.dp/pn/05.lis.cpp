#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a[]={50,4,10,8,30,100};
	vector<int> t(6,1);
	int mx=1;

	for(int i=1;i<6;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(a[i]>a[j])
			{
				t[i]=max(t[i],1+t[j]);
				if(t[i]>mx)
					mx=t[i];
			}
		}
	}
	
	for(auto &val:t)
		cout<<val<<" ";
	cout<<endl;
	cout<<t[5];
	return 0;
}