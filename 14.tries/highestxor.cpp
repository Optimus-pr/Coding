#include<bits/stdc++.h>
using namespace std;

vector<string> res;

class node{
public:
	char data;
	unordered_map<char,node *> m;
	bool terminal;

	node(char ch){
		data=ch;
		terminal=false;
	}
};

class trie{
public:
	node * root;
	trie()
	{
		root=new node('-1');
	}

	void insert(string s)
	{
		node * temp=root;
		for(auto &ch:s)
		{
			if(temp->m.count(ch)==0)
			{
				node *nn=new node(ch);
				temp->m[ch]=nn;
			}
			temp=temp->m[ch];
		}
		temp->terminal=true;
	}

	string search(string s)
	{
		string ans="";
		for(auto &ch:s)
		{
			if(root->m.count(ch)==0)
				return false;
			root=root->m[ch];
		}
		if(root->terminal)
			return true;
		return false;
	}
};

string conv(int n,int d)
{
	string ans="";
	for(int i=d-1;i>=0;i--)
	{
		if(n&(1<<i))
			ans.push_back('1');
		else 
			ans.push_back('0');
	}
	return ans;
}

int main()
{
	int n;
	cin>>n;

	trie t;

	vector<int> a(n);
	int max=-999;
	for(int i=0;i<n;i++)
	{		
		cin>>a[i];
		if(a[i]>max)
			max=a[i];
	}

	auto it=find(a.begin(),a.end(),max);

	if(it!=a.end())
		a.erase(it);

	int d=log2(max)+1;
	for(int i=0;i<n-1;i++)
	{
		string ans=conv(a[i],d);
		res.push_back(ans);
		t.insert(res[i]);
	}

	string txt=conv(max,d);

	cout<<t.search(max);

	
	return 0;
}