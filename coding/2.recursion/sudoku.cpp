#include<bits/stdc++.h>
using namespace std;

bool check(int ar[][9],int i,int j,int k)
{
	for(int l=0;l<9;l++)
	{
		if(ar[i][l]==k || ar[l][j]==k)
			return false;
	}

	int sx=(i/3)*3;
	int sy=(j/3)*3;

	for(int a=sx;a<sx+3;a++)
	{
		for(int b=sy;b<sy+3;b++)
		{
			if(ar[a][b]==k)
				return false;
		}
	}
	return true;

}


bool sudoku(int a[][9],int i,int j,int n)
{
	if(i==n)
		return true;

	if(j==n)
		return sudoku(a,i+1,0,n);

	if(a[i][j]!=0)
		return sudoku(a,i,j+1,n);

	for(int k=1;k<=n;k++)
	{
		if(check(a,i,j,k))
		{
			a[i][j]=k;
			if(sudoku(a,i,j+1,n))
				return true;
		}
	}
	a[i][j]=0;
	return false;
}

int main()
{
	int a[9][9]={{3,0,6,5,0,8,4,0,0},
				 {5,2,0,0,0,0,0,0,0},
				 {0,8,7,0,0,0,0,3,1},
				 {0,0,3,0,1,0,0,8,0},
				 {9,0,0,8,6,3,0,0,5},
				 {0,5,0,0,9,0,6,0,0},
				 {1,3,0,0,0,0,2,5,0},
				 {0,0,0,0,0,0,0,7,4},
				 {0,0,5,2,0,6,3,0,0}};

	cout<<sudoku(a,0,0,9)<<endl;
	for(int k=0;k<9;k++)
	{
		for(int l=0;l<9;l++)
			cout<<a[k][l]<<" ";
		cout<<endl;
	}
	return 0;
}