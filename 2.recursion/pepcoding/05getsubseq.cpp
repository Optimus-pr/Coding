#include<bits/stdc++.h>
using namespace std;

void printsubseq(string s,string tmp)
{
	if(s.size()==0)
	{
		cout<<tmp<<" ";
		return;
	}

	char ch=s[0];
	string rs=s.substr(1);

	printsubseq(rs,tmp+ch);
	printsubseq(rs,tmp+"");

}


vector<string> getsubseq(string s)
{
	if(s.size()==0)
	{
		vector<string> ans;
		ans.push_back("");
		return ans ;
	}

	char ch=s[0];
	string rss=s.substr(1);
	vector<string> tmp=getsubseq(rss);

	vector<string> rans;

	for(int i=0;i<tmp.size();i++)
	{
		rans.push_back(""+tmp[i]);
	}
	for(int i=0;i<tmp.size();i++)
	{
		rans.push_back(ch+tmp[i]);
	}

	return rans;
}

int main()
{
	string s;
	string tmp="";
	cin>>s;

	//vector<string> v=getsubseq(s);
	printsubseq(s,tmp);

	// for(auto &val:v)
	// 	cout<<val<<" ";
	// cout<<endl;
	
	return 0;
}