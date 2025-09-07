#include<bits/stdc++.h>
using namespace std;

int main()
{
	char s[1000];
	cin.getline(s,1000);
	int cnt=0;
	for(int i=0;i<strlen(s);i++)
		if(s[i]==' ')
			cnt++;
		
	int i=strlen(s)+2*cnt;

	int j=strlen(s);
	while(j>=0)
	{
		if(s[j]!=' ')
		{
			s[i]=s[j];
			i--;
			j--;
		}
		else if(s[j]==' ')
		{
			s[i]='0';
			s[i-1]='2';
			s[i-2]='%';
			i-=3;
			j--;
		}
	}
	cout<<s;
	return 0;
}