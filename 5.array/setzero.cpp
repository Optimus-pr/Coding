#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;

int main()
{
	int m,n;
	cin>>m>>n;

	int ar[m][n];

	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			cin>>ar[i][j];

	int c=-1;

	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(a[i][j]==0)
			{
				a[i][0]=0;
				if(j==0)
					c=0;
				else
					a[0][j]=0;
			}
		}
	}

	for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (a[i][j] != 0) {
                // check for col & row:
                if (a[i][0] == 0 || a[0][j] == 0) {
                    a[i][j] = 0;
                }
            }
        }
    }

    //first row then column
	if(a[0][0]==0)
	{
		for(int i=0;i<n;i++)
			a[0][i]=0;
	}

	if(c==0)
	{
		for(int i=0;i<m;i++)
			a[i][0]=0;
	}


	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<ar[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;

}