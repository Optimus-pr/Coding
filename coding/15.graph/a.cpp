#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

int countUniqueElements(int *a, int n, int k) {
    int count = 0;
    unordered_map<int, int> m;

    int i = 0, j = 0;

    while (j < n) {
        m[a[j]]++;

        if (j - i + 1 < k) {
            j++;
        }
        else if (j - i + 1 == k) {
            count += m.size();

            if (m[a[i]] > 1) {
                m[a[i]]--;
            }
            else {
                m.erase(a[i]);
            }

            i++;
            j++;
        }
    }

    return count;
}

int main() {
    int a[] = {1, 1, 2, 4, 2};
    int n = 5;
    int k = 3;

    cout << countUniqueElements(a, n, k) << endl;

    return 0;
}
