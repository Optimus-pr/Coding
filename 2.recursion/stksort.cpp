#include<bits/stdc++.h>
using namespace std;

void insrt(stack<int> &s,int tmp)
{
	if(s.size()==0 || s.top()<=tmp)
	{
		s.push(tmp);
		return;
	}
	int end=s.top();
	s.pop();
	insrt(s,tmp);
	s.push(end);
}

void srt(stack<int> &s)
{
	if(s.size()==0)
		return;

	int tmp=s.top();
	s.pop();
	srt(s);
	insrt(s,tmp);
}

int main()
{
	int n;
	cin>>n;

	stack<int> s;

	for(int i=0;i<n;i++)
	{
		int ele;
		cin>>ele;
		s.push(ele);
	}

	srt(s);
	while(!s.empty())
	{
		cout<<s.top()<<" ";
		s.pop();
	}
}