#include<bits/stdc++.h>
using namespace std;

int main()
{
	priority_queue<int> p;
	int n;
	cin>>n;

	int j=1,i=1;

	while(j!=n)
	{
		if(((int)log10(i)+1)==1)
        {
        	 j++;
        	 i+=2;
             p.push(i);
        
             if(p.size()>n)
                 p.pop();
        }
        else if((i/10)%2==0)
        {
        	i+=2;
            continue;
        }
        else
        {
        	j++;
        	i+=2;
            p.push(i);
        
            if(p.size()>n)
             p.pop();
        }
	}

	cout<<p.top();
	return 0;
}