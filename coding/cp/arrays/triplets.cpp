#include<bits/stdc++.h>
using namespace std;

void compute(vector<int> &v,int ts)
{
	sort(v.begin(),v.end());

	for(int i=0;i<v.size()-1;i++)
	{
		int nts=ts-v[i];
		int k=v.size()-1;
		int j=i+1;
		int sum=0;

		while(j<k){
			sum=v[j]+v[k];
			if(sum==nts)
			{
				cout<<v[i]<<" "<<v[j]<<" "<<v[k]<<endl;
				j++;
				k--;
			}
			else if(sum>nts)
				k--;
			else
				j++;
		}
	}
}

int main()
{
	int n,ts;
	cin>>n>>ts;
	vector<int> v(n);

	for(int i=0;i<n;i++)
		cin>>v[i];

	compute(v,ts);
	return 0;
}