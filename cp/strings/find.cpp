#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	getline(cin,s);

	string temp;
	cin>>temp;
	int index=s.find(temp);
	cout<<index<<" ";
	while(index!=-1)
	{
		index=s.find(temp,index+1);
		cout<<index<<" ";
	}
	return 0;
}