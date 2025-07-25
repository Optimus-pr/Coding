//if no 2 is occured 5 times we can store both in a single var i.e if the range of no is from 1-99 we have use no 100 i.e 2+5*100=502 502/100=5 occ and 502%100=2 is the no

// so the brute force approach to solve this problem is like take an array of size n but the 0th index will be wasted as the no will be from [1,n] that can be optimised read this first iterate over the given array and increment the corresponding ind of the new array later we can get to know that 0 => missing more than 1 => repeated
//now to remove wasting 0th index we can just store inc ele-1 in the new array so that ele 1 => new[1-1]++

//so instead we can just sub the given array by 1 init later while returning the ans we can just return ind+1
//we can optimize it still further without using an array i.e we can use the first point i.e we can store both the elem and the occu of the same in the same array but here the thing is we don't know lilke 2 is occuring 6 times so whenever we get the ele/n > 1

vector<int> findTwoElement(vector<int>& arr) {
    // code here
    int add=arr.size()+1,n=arr.size();
    vector<int> v(2,0);
    for(int i=0;i<n;i++)
        arr[i]-=1;
    for(int i=0;i<n;i++)
    {
        int ele=arr[i]%add;
        arr[ele]+=add;
    }
    for(int i=0;i<n;i++)
    {
        if(arr[i]/add==2)
            v[0]=i+1;
        else if(arr[i]/add==0)
            v[1]=i+1;
    }
    return v; 
}