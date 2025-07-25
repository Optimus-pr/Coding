//asuming winsize=3 print the max from the window use deque to keep track of max ele as if there is 3 2 1 -2 after printing 3 we won't be knowing the next greater here we first 3 is greater so pushfront 3 then eventhough 2 is smaller than 3 pushback as it may be useful but if there was 1 2 3 -2 init 1 is max so pushfrnot 1 then 2 is gt 1 so pop 1 as it won't be useful further i.e smaller ele to the right of greater will be useful so pushback but ele smaller that max value to the left won't be useful

#include<bits/stdc++.h>
using namespace std;

vector<int> maxOfSubarrays(vector<int>& a, int k) {
        // code here
        vector<int> ans;
        int i=0,j=0,n=a.size();
	deque<int> q;

	while(j<n)
	{
		while(!q.empty() && q.back()<a[j])
		    q.pop_back();
		q.push_back(a[j]);

		if(j-i+1<k)
			j++;
		else if(j-i+1==k)
		{
			ans.push_back(q.front());
			if(a[i]==q.front())
				q.pop_front();
			i++;
			j++;
		}
	}
        return ans;
        
    }

int main()
{
	int n;
	cin>>n;

	int a[n];

	for(int i=0;i<n;i++)
		cin>>a[i];

	printmax(a,n);
}