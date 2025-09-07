//if an 'O' is surrounded by 'X' in all four sides then flip it to X else keep it as it is.

class Solution {
public:
    void dfs(int x, int y, int m, int n, vector<vector<int>>& vis, vector<vector<char>>& b) {
        if (x < 0 || y < 0 || x >= m || y >= n || vis[x][y] == 1 || b[x][y] == 'X')
            return;

        vis[x][y] = 1;

        dfs(x + 1, y, m, n, vis, b);
        dfs(x, y + 1, m, n, vis, b);
        dfs(x - 1, y, m, n, vis, b);
        dfs(x, y - 1, m, n, vis, b);
    }

    void solve(vector<vector<char>>& b) {
        
        int m = b.size(), n = b[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if ((i == 0 || j == 0 || i == m - 1 || j == n - 1) && b[i][j] == 'O') {
                    dfs(i, j, m, n, vis, b);
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (vis[i][j] == 0)
                    b[i][j] = 'X';
                else if (vis[i][j] == 1)
                    b[i][j] = 'O';
            }
        }
    }
};
