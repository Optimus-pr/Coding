#include<bits/stdc++.h>
using namespace std;

int main()
{
	string str;
	getline(cin,str);

	stringstream ss(str);
	string buffer;
	while(getline(ss,buffer,' '))
	{
		cout<<buffer<<endl;
	}
	return 0;
}