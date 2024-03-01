#include <bits/stdc++.h>
using namespace std;

long long int rec(long long int n, vector<long long int> &v, set<set<long long int> > &s) {
    if (n == 0) {
        set<long long int> t;
        s.insert(t);
        return 1;
    }

    if (n < 0)
        return 0;

    if (v[n] != -1)
        return v[n];

    long long int a = 0, b = 0, c = 0;

    // Use a new set for each recursive call
    set<long long int> t;

    t.insert(3);
    a = rec(n - 3, v, s);
    t.erase(3);

    t.insert(5);
    b = rec(n - 5, v, s);
    t.erase(5);

    t.insert(10);
    c = rec(n - 10, v, s);
    t.erase(10);

    return v[n] = a + b + c;
}

int main() {
    long long int n;
    cin >> n;
    vector<long long int> v(n + 1, -1);
    set<set<long long int> > s;
    rec(n, v, s);
    cout << s.size();
    return 0;
}
