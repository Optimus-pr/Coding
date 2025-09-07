int combi(int n, int r) {
    if (r > n - r)  
        r = n - r;
    
    int ans = 1;
    for (int i = 0; i < r; ++i) {
        ans = (ans * (n - i)) / (i + 1);
    }
    return ans;
}

