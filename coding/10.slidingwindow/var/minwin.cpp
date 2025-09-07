#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;

int minsub(string &s,string &p)
{
	unordered_map<char,int> m;
	int i=0,j=0,cnt=0,n=s.size(),mcnt=999;
	
	for(auto &it:p)
		m[it]++;
	for(auto &it:m)
		cnt++;
	
	while(j<n)
	{
		if(m.find(s[j])!=m.end()) 
		{
			if(--m[s[j]]==0)cnt--;
		}


		if(cnt>0)
			j++;
		else if(cnt==0)
		{ 
			while(cnt==0)
			{
				mcnt=min(mcnt,j-i+1);
				if(m.find(s[i])!=m.end())
				{
					// if((++m[s[i]])>0)
					if(((++m[s[i]])==1))
						cnt++;
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
	string s,p;
	cin>>s>>p;

	
	cout<<minsub(s,p);
}