#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
bool found=false;
void chess(vector<vector<int> > &v,int r,int c,int n,int cnt)
{	


	if(r<0 || c<0 || r>=n || c>=n || v[r][c]>0|| found)
		return;
	v[r][c]=cnt;

	if(cnt==n*n)
	{
		for(auto &val:v){
			for(auto &info:val)
				cout<<info<<" ";
			cout<<endl;
		}
		cout<<endl;
		found=true;
		return;

	}

	chess(v, r - 2, c - 1, n,cnt+1);
    chess(v, r - 2, c + 1, n,cnt+1);
    chess(v, r - 1, c - 2, n,cnt+1);
    chess(v, r - 1, c + 2, n,cnt+1);
    chess(v, r + 1, c - 2, n,cnt+1);
    chess(v, r + 1, c + 2, n,cnt+1);
    chess(v, r + 2, c - 1, n,cnt+1);
    chess(v, r + 2, c + 1, n,cnt+1);
    v[r][c]=0;
}

int main()
{
	int n,r,c,cnt=1;
	cin>>n>>r>>c;
	vector<vector<int> > v(n,vector<int> (n,0));
	chess(v,r,c,n,cnt);
	return 0;
}	