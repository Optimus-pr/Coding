#include<bits/stdc++.h>
using namespace std;

vector<int> ksorted(int *a,int* b,int *c,int p,int q,int r)
{
	priority_queue<pair<int*,pair<int,int> > ,vector<pair<int*,pair<int,int> > >,greater<pair<int*,pair<int,int> > > > min;
	min.push(make_pair(a,make_pair(a[0],1)));
	min.push(,b[0]);
	min.push(a,c[0]);

	int i=1,j=1,k=1,cnt=0;

	while(cnt!=2)
	{

	}
}

int main()
{
	int a[]={0,6,9};
	int b[]={1,5,8};
	int c[]={2,3,4};
	

	vector<int> v=ksorted(a,b,c,3,3,3);

	for(auto &val:v)
		cout<<val<<" ";
	cout<<endl;
}