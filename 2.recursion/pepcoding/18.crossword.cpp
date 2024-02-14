//this problem will solve the crossword puzzle by filling the words which are given in the particular slots it will also return more than one solutions if exists


#include<bits/stdc++.h>
using namespace std;

bool canplacehor(vector<vector<char> > v,int i,int j,string s)
{
	if(j-1>=0 && v[i][j-1]!='+')
		return false;
	else if(j+s.size()<=v[0].size() && v[i][j+s.size()]!='+')
		return false;

	for(int jj=0;jj<s.size();jj++)
	{
		if(j+jj>=v[0].size())
			return false;
		if(v[j+jj]=='-' || v[j+jj]==s[jj])
			continue;
		else
			return false;
	}
	return true;
}

bool canplacever(vector<vector<char> > v,int i,int j,string s)
{
	if(i-1>=0 && v[i-1][j]!='+')
		return false;
	else if(i+s.size()<v[0].size() && v[i+s.size()][j]!='+')
		return false;

	for(int ii=0;ii<s.size();ii++)
	{
		if(i+ii>=v.size())
			return false;
		if(i+ii=='-' || i+ii==s[ii])
			continue;
		else
			return false;
	}
	return true;
}

vector<bool> placehor(vector<vector<char> > v,int i,int j,string s)
{
	vector<bool> bl(s.size(),false);
	for(int jj=0;jj<s.size();jj++)
		if(v[i][j+jj]=='-')
		{
			bl[jj]=true;
			v[i][j+jj]=s[jj];
		}
	return bl;
}

vector<bool> placever(vector<vector<char> > v,int i,int j,string s)
{
	vector<bool> bl(s.size(),false);
	for(int ii=0;ii<s.size();ii++)
		if(v[i+ii][j]=='-')
		{
			bl[ii]=true;
			v[i+ii][j]=s[ii];
		}
	return bl;
}

void unplacehor(vector<vector<char> > v,int i,int j,string s,vector<bool> bl)
{
	for(int jj=0;jj<s.size();jj++)
	{
		if(bl[jj])
			v[i][j+jj]='-';

	}
}

void unplacever(vector<vector<char> > v,int i,int j,string s,vector<bool> bl)
{
	for(int ii=0;ii<s.size();ii++)
	{
		if(bl[ii])
			v[i+ii][j]='-';
		
	}
}
		

void solution(vector<vector<char> > v,vector<string> s,int id)
{
	if(id==s.size())
	{
		for(auto &val:v)
		{
			for(auto &info:val)
				cout<<info<<" ";
			cout<<endl;
		}
		return;
	}

	string word=s[id];

	for(int i=0;i<v.size();i++)
	{
		for(int j=0;j<v[0].size();j++)
		{
			if(v[i][j]=='-'||v[i][j]==word[0])
			{
				if(canplacehor(v,i,j,word))
				{
					vector<bool> bl=placehor(v,i,j,word);
					solution(v,s,id+1);
					unplacehor(v,i,j,word,bl);
				}
			}

			if(v[i][j]=='-'||v[i][j]==word[0])
			{
				if(canplacever(v,i,j,word))
				{
					vector<bool> bl=placever(v,i,j,word);
					solution(v,s,id+1);
					unplacever(v,i,j,word,bl);
				}
			}
		}
	}
}