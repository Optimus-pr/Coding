//heap is complete binary tree where parent nodes are always greater than child nodes

//if we are give with a vector and we need to create heap out of that we have 2 ways one is manual way and another is stl manual way is demonstrated here but if we want to use stl then there is 2 more ways i.e 
// a.priority_queue<int> p;
// b.priority_queue<int> p(v.begin(),v.end());
// here a takes 0(nlogn) where as b takes 0(n)

#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int> &v,int i,int n)
{
	int largest=i;
	int left=2*i+1;
	int right=2*i+2;

	if(left<n && v[left]>v[largest])
		largest=left;
	if(right<n && v[right]>v[largest])
		largest=right;
	if(largest!=i)
	{
		swap(v[largest],v[i]);
		heapify(v,largest,n);
	}
}

void createHeap(vector<int> &v,int n)//this is the top down approach this will take o(n) for creation if we go with bottom-up approach it would take o(nlogn)
{
	for(int i=n/2-1;i>=0;i--)//here we are starting from n/2-1 because in top down approach there is no need to check for leaf nodes as there will be no child for them so we need to go to that node which will have child
		heapify(v,i,n);
}

void heapSort(vector<int>&v,int n)
{
    while(n)
    {
        swap(v[0],v[n-1]);//here we are not taking extra space to store the array we are modifying the given array only recursion stack space is extra
        heapify(v,0,n-1);
        n--;
    }
}

int main()
{
	vector<int> v={2,3,4,1,5,10};//since array is given already we can do creation in o(n) time if runtime input then we should go for bottom approach that will take o(nlogn);

	//normally when we insert something in prioq it takes logn per element so creation takes o(nlogn)
	createHeap(v,6);
	heapSort(v,6);
	for(auto &val:v)
	    cout<<val<<" ";
	cout<<endl;
	return 0;
}

