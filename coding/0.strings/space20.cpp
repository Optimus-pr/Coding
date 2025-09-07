#include<bits/stdc++.h>
using namespace std;

void space(char *a)
{
	int i,cnt=0;

	for(i=0;a[i]!='\0';i++)
	{
		if(a[i]==' ')
			cnt++;
	}

	int j=i+cnt*2;

	while(i>=0)
	{
		if(a[i]!=' ')
		{
			a[j]=a[i];
			i--;
			j--;
		}
		else
		{
			a[j]='0';
			a[j-1]='2';
			a[j-2]='%';
			i--;
			j-=3;
		}
	}

}

int main()
{
	char a[1000];

	cin.getline(a,1000);

	space(a);
	cout<<endl;
	for(int i=0;a[i]!=0;i++)
		cout<<a[i];

}