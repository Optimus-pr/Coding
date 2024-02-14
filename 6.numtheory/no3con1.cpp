#include<bits/stdc++.h>
using namespace std;

void printbin(int n)
{
	for(int i=12;i>=0;i--)
	{
		if((n>>i)&1)
			cout<<"1";
		else
			cout<<"0";
	}
	cout<<endl;
}

int main()
{
	int n,t,j=0;
	cin>>n;

	int cnt=0,l=0;
	int N=log2(n)+1;
	printbin(n);

	for(int i=0;i<N;i++)
	{
		if(n&(1<<i))
		{
			l=i;
			cnt++;
			
		}
		else 
		{
			while(cnt>=3)
			{
				if(cnt%3==0)
				{
					n=n&(~(1<<(l-2)));
					l-=3;
					cnt-=3;
				}
				else if(cnt>5)
				{
					t=l-cnt+2;
					while(l>t)
					{
						
						n=n&(~(1<<t));
						t+=3;
						cnt-=3;
					}
				}
				else if(cnt==4 || cnt==5)
				{
					n=n&(~(1<<(l-2)));
					cnt-=3;
				}
			}
			cnt=0;
		}
	}
	t=l-cnt+2;
	while(cnt>=3)
	{
		if(cnt%3==0)
		{
			n=n&(~(1<<(l-2)));
			l-=3;
			cnt-=3;
		}
		else if(cnt>5)
		{
			while(l>t)
			{
				
				n=n&(~(1<<t));
				t+=3;
				cnt-=3;
			}
		}
		else if(cnt==4 || cnt==5)
		{
			n=n&(~(1<<(l-2)));
			cnt-=3;
		}
	}
	printbin(n);
	return 0;
}