//here rows will be sorted but columns are not sorted last ele of prev row will be smaller than first element of current row

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

	int l=0,h=n*m-1,mid,flag=0;

	while(h-l>1)
	{
		mid=(h+l)/2;

		if(a[mid/n][mid%n]<=key)
			l=mid;
		else
			h=mid-1;
	}
	if(a[l/n][l%n]==key)
		cout<<l/n<<" "<<l%n<<endl;
	else if(a[h/n][h%n]==key)
		cout<<h/n<<" "<<h%n<<endl;
	else
		cout<<"-1";
}