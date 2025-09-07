//rows and cols both are sorted
//last ele of prev row need not be smaller than first ele of current row =>we can't directly use binary search like in previous case


#include<bits/stdc++.h>
using namespace std;

int main()
{
	int m,n,key;
	cin>>m>>n>>key;

	int a[m][n];

	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			cin>>a[i][j];

	int i=0,j=n-1,flag=0;

	while(i<m && j<n)
	{
		if(a[i][j]==key)
		{
			flag=1;break;
		}
		else if(a[i][j]>key)
			j--;
		else
			i++;
	}

	if(flag)
		cout<<"1";
	else
		cout<<"0";
	return 0;
}