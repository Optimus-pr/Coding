// //1) to generate the whole matrix which takes 0(n^2) space and time
// #include<bits/stdc++.h>
// using namespace std;

// int main()
// {
// 	int n;
// 	cin>>n;

// 	int a[n][n];

// 	a[0][0]=1;

// 	for(int i=0;i<n;i++)
// 	{
// 		for(int j=0;j<=i;j++)
// 		{
// 			if(j==0 || (i==j))
// 				a[i][j]=1;
// 			else
// 				a[i][j]=a[i-1][j]+a[i-1][j-1];
// 		}
// 	}

// 	for(int i=0;i<n;i++)
// 	{
// 		for(int j=0;j<=i;j++)
// 		{
// 			cout<<a[i][j]<<" ";
// 		}
// 		cout<<endl;
// 	}
// }

// 2) if row and col numbers are given we can simply use the combination formula where factorial is found whihc takes 0(n) time and 0(1) space;

//3)if row number is given and the corresponding row of pascal triangle need to be found

// even this can be done using approach 2 using formula but it takes 0(n) for n times i.e 0(n^2)
//so we must optimise it bit 


#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;

	int ans=1;
	cout<<ans<<" ";
	int a=n,b=1;
	for(int i=1;i<=n;i++)
	{
		ans=ans*(a--)/(b++);
		cout<<ans<<" ";
	}
}