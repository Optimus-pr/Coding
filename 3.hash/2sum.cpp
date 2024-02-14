#include<unordered_map>
#include<iostream>

using namespace std;

int main()
{
	int n,sum;
	cin>>n>>sum;

	int a[n];

	for(int i=0;i<n;i++)
		cin>>a[i];

	unordered_map<int,int> u;//use unordered_set

	for(int i=0;i<n;i++)
	{
		
		if(u.find(sum-a[i])!=u.end())
		{
			cout<<(u[sum-a[i]])<<" "<<a[i]<<endl;
			break;
		}
		else
			u[a[i]]=i;
	}

}