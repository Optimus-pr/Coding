#include<bits/stdc++.h>
using namespace std;

vector<string> getpathjumps(int sr,int sc,int dr,int dc)
{

	if(dr==sr && sc==dc)
	{
		vector<string> v;
		v.push_back("");
		return v;
	}

	vector<string> right;
	vector<string> down;
	vector<string> diag;
	vector<string> ans;

	for(int i=1;i<=dc-sc;i++)
	{
		right=getpathjumps(sr,sc+i,dr,dc);
		for(auto &val:right)
			ans.push_back("r"+to_string(i)+val);
	}

	for(int i=1;i<=dr-sr;i++)
	{
		right=getpathjumps(sr+i,sc,dr,dc);
		for(auto &val:right)
			ans.push_back("d"+to_string(i)+val);
	}

	for(int i=1;i<=dr-sr && i<=dc-sc;i++)
	{
		diag=getpathjumps(sr+i,sc+i,dr,dc);
		for(auto &val:diag)
			ans.push_back("D"+to_string(i)+val);
	}

	return ans;
}

void printpathjumps(int r,int c,int dr,int dc,string s)
{

	if(r==dr && c==dc)
	{
		cout<<s<<" ";
		return;
	}
	else if(r>dr || c>dc)
		return;

	for(int i=1;i<=dc-c;i++)
		printpathjumps(r,c+i,dr,dc,"r"+to_string(i)+s);

	for(int i=1;i<=dr-r;i++)
		printpathjumps(r+i,c,dr,dc,"d"+to_string(i)+s);

	for(int i=1;i<=dc-c && i<=dr-r;i++)
		printpathjumps(r+i,c+i,dr,dc,"D"+to_string(i)+s);

}

int main()
{
	int m,n;
	cin>>m>>n;

	// vector<string> v=getpathjumps(1,1,m,n);
	printpathjumps(1,1,m,n,"");
	// for(auto &val:v)
	// 	cout<<val<<" ";
	// cout<<endl;
	// cout<<v.size();

	return 0;
}

