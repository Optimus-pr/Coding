//the same sol is for find the max val in bitonic array where bitonic array is the one which starts increasing after one point it will start decreasing

#include<bits/stdc++.h>
using namespace std;

/* The function should return the index of any
   peak element present in the array */

// arr: input array
// n: size of array

  int peakElement(int a[], int n)
  {
     int s = 0, e = n - 1, mid
  while (s <= e) {
      mid = s + (e - s) / 2
      if ((mid == 0 || a[mid] >= a[mid - 1]) && (mid == n - 1 || a[mid] >= a[mid + 1])) {
          return mid;
      } else if (mid > 0 && a[mid - 1] >= a[mid]) {
          e = mid - 1;
      } else {
          s = mid + 1;
      }
  
  return -1;
  }


int main()
{
	int n;
	cin>>n;

	int a[n];

	for(int i=0;i<n;i++)
		cin>>a[i];

	cout<<peak(a,0,n-1);

	return 0;
}