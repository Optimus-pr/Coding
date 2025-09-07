//here init we maintain a map of pattern and cnt containing number of unique char which will prevent traversing the map each time for the eg aabaabaa and aaba map init contain a-3 b-1 cnt=2 now after first win a-0 b-0 when a is 0 or b is 0 cnt is decre and when cnt is 0 implies all the char are used ,and we should also take care not to update any char which is not present in the map which won't be useful anyways ,and in line 33 we may see that only when cnt was 0 incr i will incr cnt i.e in baab a-1 b- -1 cnt-1 which implies we need one more a and we have extra b so when the windo moves to aaba a-0 b-0 cnt should be 1 only so check if the incr mented char is required or not if not then no need to incr cnt

#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

int cnt(string &s,string &p)
{
	int n=s.size(),l=p.size();

	int i=0,j=0,cnt=0,mcnt=0;
	unordered_map<char,int> m;
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
		if(cnt==0)mcnt++;

		if(j-i+1<l)
			j++;
		else if(j-i+1==l)
		{
			if(m.find(s[i])!=m.end())
			{
				if(++m[s[i]]==1)
					cnt++;
			}
			i++;
			j++;
		}
	}
	return mcnt;
}

int main()
{
	string s,p;
	cin>>s>>p;

	cout<<cnt(s,p);

}