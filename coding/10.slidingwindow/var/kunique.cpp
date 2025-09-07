//this is a var sized window problem here we need to maximize the window such that it can have k unique char 

#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

int kunique(string a,int n)
{
	unordered_map<char,int> m;
	int i=0,j=0,cnt=0,mcnt=0;

	while(j<n)
	{
		if(m.find(a[j])==m.end())
		cnt++;

		m[a[j]]++;
	
		if(cnt<3)
			j++;
		else if(cnt==3)
		{
			mcnt=max(mcnt,j-i+1);
			j++;
		}
		else
		{
			while(cnt!=3)
			{
				if(--m[a[i]]==0){
					cnt--;
					m.erase(a[i]);
				}
				i++;
			}
			j++;
		}
	}

	

	return mcnt;
}

int main()
{
	string s;
	cin>>s;

	

	cout<<kunique(s,s.size());
}