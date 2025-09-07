//refer pepcoding level2 backtracking question 3 for this

#include<bits/stdc++.h>
using namespace std;

int solution(vector<string> v,int id,vector<int> freq,vector<int> score)
{
	if(id==v.size())
		return 0;

	int yes,no,scr=0;

	no=solution(v,id+1,freq,score);

	string word=v[id];
	bool flag=true;

	for(auto &ch:word)
	{
		if(--freq[ch-'a']==0)
			flag=false;
		scr+=score[ch-'a'];
	}

	if(flag)
		yes=scr+solution(v,id+1,freq,score);

	for(auto &ch:word)
		freq[ch-'a']++;

	return max(yes,no);
}