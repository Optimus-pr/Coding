#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin>>s;

	int i=0,j=0,cnt=0,mx=-999;
	unordered_map<char,int> m;

	while(j<s.size())
	{
		if(m.find(s[j])==m.end())
			cnt++;

		m[s[j]]++;

		if(cnt<3)
			j++;
		else if(cnt==3)
		{
			mx=max(mx,j-i+1);
			j++;
		}
		else
		{
			while(cnt!=3)
			{
				if(--m[s[i]]==0)
				{
					m.erase(s[i]);
					cnt--;
				}
				i++;
			}
			j++;
		}
	}	
	cout<<mx;
	return 0;
}