//here we need to return the distance of nearest 0 to each cell

class Solution {
public:
    bool isvalid(int x, int y, int m, int n) {
        if (x < 0 || y < 0 || x >= m || y >= n)
            return false;
        return true;
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        vector<vector<int>> dis(m, vector<int>(n, 0));
        queue<pair<pair<int, int>, int>> q;

        vector<pair<int, int>> mv = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (mat[i][j] == 0) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }

        while (!q.empty()) {
            int x = q.front().first.first, y = q.front().first.second, d = q.front().second;
            q.pop();
            dis[x][y] = d;
            for (auto& mov : mv) {
                int nx = x + mov.first, ny = y + mov.second;
                if (!isvalid(nx, ny, m, n)||vis[nx][ny] == 1)
                    continue;
                q.push({{nx, ny}, d + 1});
                vis[nx][ny] = 1;
            }
        }
        return dis;
    }
};
