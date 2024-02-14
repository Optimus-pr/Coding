//when the given key is sub by any of the ele present in the array then we will get min abs diff if the key is not present in the array then either ele before the key will be the answer or ele next to the key will be the answer

#include<iostream>

using namespace std;

int diff(vector<int> &v,int k)
{
	int s=0,e=v.size()-1,mid;
	while(s<=e)
	{
		int mid=(s+e)/2;
		if(v[mid]==k)
			return 0;
		else if(v[mid]<k)
			s=mid+1;
		else
			e=mid-1;
	}
	int min1=abs(v[s]-k);
	int min2=abs(v[e]-k);
	return min(min1,min2);
}

int main()
{
	int n,k;
	cin>>n>>k;

	vector<int> v(n);

	for(int i=0;i<n;i++)
		cin>>v[i];

	cout<<diff(v,k);

	return 0;
}