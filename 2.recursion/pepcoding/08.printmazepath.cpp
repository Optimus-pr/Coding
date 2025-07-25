#include<bits/stdc++.h>
using namespace std;

vector<string> getpath(int sr,int sc,int dr,int dc)
{

	if(dr==sr && sc==dc)
	{
		vector<string> v;
		v.push_back("");
		return v;
	}

	vector<string> right;
	vector<string> down;
	vector<string> ans;

	if(sc<dc)
		right=getpath(sr,sc+1,dr,dc);

	if(sr<dr)
		down=getpath(sr+1,sc,dr,dc);

	for(auto &val:right)
		ans.push_back("r"+val);

	for(auto &val:down)
		ans.push_back("d"+val);

	return ans;
}

void printpath(int sr,int sc,int dr,int dc,string tmp)
{
	if(sr>=dr || sc>=dc)
		return;
	if(sr==dr && sc==dc)
	{
		cout<<tmp<<" ";
		return;
	}
	printpath(sr+1,sc,dr,dc,"d"+tmp);
	printpath(sr,sc+1,dr,dc,"r"+tmp);
}

int main()
{
	int m,n;
	cin>>m>>n;

	vector<string> v=printpath(0,0,m-1,n-1);
	for(auto &val:v)
		cout<<val<<" ";
	cout<<endl;
	cout<<v.size();

	return 0;
}