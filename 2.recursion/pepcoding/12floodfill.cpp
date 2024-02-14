#include<bits/stdc++.h>
using namespace std;

void floodfill(vector<vector<int> > &v, int sr, int sc, int dr, int dc, vector<vector<int> > &vis, string t) {
    if (sc < 0 || sr < 0 || sr >= v.size() || sc >= v[0].size() || vis[sr][sc] == 1 || v[sr][sc] == 1)
        return;

    if (sr == dr && sc == dc) {
        cout << t << " ";
        return;
    }

    vis[sr][sc] = 1;
    floodfill(v, sr - 1, sc, dr, dc, vis, t + "t");
    floodfill(v, sr, sc - 1, dr, dc, vis, t + "l");
    floodfill(v, sr + 1, sc, dr, dc, vis, t + "d");
    floodfill(v, sr, sc + 1, dr, dc, vis, t + "r");
    vis[sr][sc] = 0;
}


int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int> > v(m, vector<int>(n, 0));
    vector<vector<int> > vis(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> v[i][j];

    floodfill(v, 0, 0, m - 1, n - 1, vis, "");
    return 0;
}
