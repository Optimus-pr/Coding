//Given a string s containing 0's and 1's. You have to return the smallest positive integer C, such that the binary string can be cut into C pieces and each piece should be of the power of 5  with no leading zeros.eg 101101 output is 3

#include<bits/stdc++.h>
using namespace std;

bool ispower(int n)
{
	int flag=0;
	while(n%5==0 && n>1)
	{
		flag=1;
		n/=5;
	}
	if(flag && n==1)
		return true;
	else
		return false;
}

int main()
{
	string s;
	cin>>s;

	reverse(s.begin(),s.end());

	int i=0,j=0,sum=0,t=1,p,cnt=0,mcnt=-1;

	while(i<s.size())
	{
		p=(s[j]-'0')*t;
		t*=2;
		sum+=p;

		if(ispower(sum))
		{
			cnt++;
			cout<<s.substr(i,j+1)<<endl;
			mcnt=max(cnt,mcnt);
			i=j+1;
			// s.erase(0,j+1);
			j=i;
			sum=0;
			t=1;
		}
		else
		{
			j++;
			if(j==s.size())
			{
				// if(ispower(sum))
				// {
				// 	cnt++;
				// 	cout<<s.substr(i,j+1)<<endl;
				// }
				while(s[i]=='0')
					i++;
				j=i;
				sum=0;
				t=1;
				cnt=0;
			}
		}

	}

	cout<<mcnt;

	return 0;
}