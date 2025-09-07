#include<bits/stdc++.h>
using namespace std;

class node{
public:
	char data;
	unordered_map<char,node*> m;
	bool terminal;

	node(char ch)
	{
		data=ch;
		terminal=false;
	}
};

class trie{
public:

	node * root;

	trie(){
		root=new node('/0');
	}

	void insert(string s)
	{
		node *t=root;
		for(char ch:s)
		{
			if(t->m.count(ch)==0)
			{
				node * nn= new node(ch);
				t->m[ch]=nn;
			}
			t=t->m[ch];
		}
		t->terminal=true;
	}

	bool search(string s)
	{
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

int main()
{
	trie t;
	t.insert("new");
	t.insert("news");
	t.insert("nature");
	t.insert("apple");

	cout<<t.search("new");
	return 0;


}