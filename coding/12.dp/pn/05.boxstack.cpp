//here you are given with l,w,h you have 2 return the number of boxes which can be stacked on top of each other 
//conditions:- the box on the top should have l,w,h strictly less than the boxes below it

#include<bits/stdc++.h>
using namespace std;

struct box
{
	int h,w,l;
};

bool cmp(box &a,box &b)
{
	return a.h<b.h;
}

int main()
{
	int n;
	cin>>n;

	vector<box> b(n);

	for(int i=0;i<n;i++)
		cin>>b[i].l>>b[i].w>>b[i].h;

	sort(b.begin(),b.end(),cmp);

	vector<int> t(n);
	t[0]=b[0].h;

	int mx=0;
	for(int i=1;i<n;i++)
	{
		t[i]=b[i].h;
		for(int j=0;j<i;j++)
		{
			if(b[j].l<b[i].l && b[j].w<b[i].w && b[j].h<b[i].h)
			{
				t[i]=max(t[i],t[j]+b[i].h);
				if(t[i]>mx)
					mx=t[i];
			}
		}
	}
	
	cout<<mx;
	return 0;
}
