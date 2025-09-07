// given a decimal no do complement of it and return the decimal
int findComplement(int num) {
    int ans=0,rem,mul=1;
    while(num)
    {
        rem=num%2;
        ans+=!rem*mul;
        mul=mul*1LL*2;
        num/=2;
    }
    return ans;
}