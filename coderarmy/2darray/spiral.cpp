vector<int> spiralOrder(vector<vector<int>>& v) {
    if (v.empty()) return {};

    int top = 0, bottom = v.size() - 1;
    int left = 0, right = v[0].size() - 1;
    vector<int> ans;

    while (top <= bottom && left <= right) {
        // Traverse from left to right
        for (int i = left; i <= right; ++i)
            ans.push_back(v[top][i]);
        top++;

        // Traverse from top to bottom
        for (int i = top; i <= bottom; ++i)
            ans.push_back(v[i][right]);
        right--;

        // Traverse from right to left (check top <= bottom)
        if (top <= bottom) {
            for (int i = right; i >= left; --i)
                ans.push_back(v[bottom][i]);
            bottom--;
        }

        // Traverse from bottom to top (check left <= right)
        if (left <= right) {
            for (int i = bottom; i >= top; --i)
                ans.push_back(v[i][left]);
            left++;
        }
    }

    return ans;
}