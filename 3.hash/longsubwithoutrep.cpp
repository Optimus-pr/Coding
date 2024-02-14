#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

int main()
{
	string s;
	getline(cin,s);

	unordered_map<int,int> u;

	int i=0,j=0,ti,tj,n=s.size(),mcnt=-999,cnt=0;

	while(j<n)
	{
		if(u.find(s[j])!=u.end())
		{
			if(cnt>mcnt)
			{
				mcnt=cnt;
				ti=i;
				tj=j-1;
			}
			cnt=0;
			i=u[s[j]]+1;
			j=i;
			u.clear();
		}
		else
		{
			cnt++;
			u[s[j]]=j;
			j++;
		}
	}

	if(mcnt==-999)//eg chinmay 
		cout<<s;
else
	for(int i=0;i<mcnt;i++)
		cout<<s[ti++];

}