//reverse if the ans goes beyond intmax or intmin return 0
int reverse(int x) {
    int ans=0,rem;
    while(x)
    {
        rem=x%10;
        if(ans*1LL*10>INT_MAX || ans*1LL*10<INT_MIN)
            return 0;
        ans=ans*10+rem;
        x/=10;
    }
    return ans;
}