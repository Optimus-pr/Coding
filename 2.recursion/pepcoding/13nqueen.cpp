#include<bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int> > &ch,int r,int c)
{
	for(int i=r-1,j=c;i>=0;i--)
		if(ch[i][j]==1)
			return false;
	for(int i=r-1,j=c-1;i>=0 && j>=0;i--,j--)
		if(ch[i][j]==1)
			return false;
	for(int i=r-1,j=c+1;i>=0 && j<ch.size();i--,j++)
		if(ch[i][j]==1)
			return false;
	return true;
}

// void nqueen(vector<vector<int> > &c,string t,int i)
// {
// 	if(i==c.size())
// 	{
// 		cout<<t<<endl;
// 		return;
// 	}

// 	for(int j=0;j<c.size();j++)
// 	{
// 		if(isSafe(c,i,j))
// 		{
// 			c[i][j]=1;
// 			nqueen(c,t+to_string(i)+"-"+to_string(j)+",",i+1);
// 			c[i][j]=0;
// 		}
// 	}

// }


//here we are using 3 seperate array to reduce time of checking if that particular column or diagonal or reversediagonal is occupied or not 

void nqueen(vector<vector<int> > &c,int i,vector<int> &col,vector<int> &diag,vector<int> &rdiag,string t)
{
	if(i==c.size())
	{
		cout<<t<<"."<<endl;
		return;
	}

	for(int j=0;j<c.size();j++)
	{
		if(col[j]==0 && diag[i+j]==0 && rdiag[i-j+c.size()-1]==0)
		{
			c[i][j]=1;
			col[j]=1;
			diag[i+j]=1;
			rdiag[i-j+c.size()-1]=1;

			nqueen(c,i+1,col,diag,rdiag,t+" "+to_string(i)+"-"+to_string(j)+",");

			col[j]=0;
			diag[i+j]=0;
			rdiag[i-j+c.size()-1]=0;
			c[i][j]=0;
		}
	}
}

int main()
{
	int n;
	cin>>n;

	vector<vector<int> > c(n,vector<int>(n,0));
	//nqueen(c,"",0);

	// nqueen branch and bound approach
	vector<int> col(n,0);
	vector<int> diag(2*n-1,0);
	vector<int> rdiag(2*n-1,0);
	nqueen(c,0,col,diag,rdiag,"");
	return 0;
}