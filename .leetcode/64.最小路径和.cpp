/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

// @lc code=start
class Solution {
   public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> f(m, vector<int>(n, INT_MAX));
        f[0][0] = grid[0][0];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i) f[i][j] = min(f[i][j], f[i - 1][j] + grid[i][j]);
                if (j) f[i][j] = min(f[i][j], f[i][j - 1] + grid[i][j]);
            }
        }

        return f[m - 1][n - 1];
    }
};

class Solution {
   public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> f(m + 1, vector<int>(n + 1, 0));
        f[0][0] = grid[0][0];
        for (int i = 1; i < m; ++i) f[i][0] = f[i - 1][0] + grid[i][0];
        for (int j = 1; j < n; ++j) f[0][j] = f[0][j - 1] + grid[0][j];
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j)
                f[i][j] = min(f[i][j - 1] + grid[i][j], f[i - 1][j] + grid[i][j]);
        }
        return f[m - 1][n - 1];
    }
};
// @lc code=end
