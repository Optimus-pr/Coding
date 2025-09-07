/*
	normal approach 
	this takes logn time but for n elements it takes nlogn time

	while(n)
	{
		if(n&1)cnt++;
		n>>=1;
	}
*/


//brian kernighan's algorithm

/*
complexity of this approach is same as above

	one imp obs is that if we sub 1 from any number its right most bit will be unset and the bits to the right of unset bit will be toggled i.e let use take 8 1000 if we sub 1 from this we get 7 i.e 0111 we can see the right most bit in 8 is unset and remaining bits are toggled we can use this fact to find the number of set bits in a number 
	a)init cnt=0;
	b)until n is 0 do
	{
		n=n&(n-1);
		cnt++;
	}
	return n;
*/

