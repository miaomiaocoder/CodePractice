/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
class Solution {
    // 注意这里dx, dy要保持一个螺旋顺序
    int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

   public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> res;
        int x = 0, y = 0;
        int d = 0;
        for (int i = 0; i < m * n; ++i) {
            res.emplace_back(matrix[x][y]);
            matrix[x][y] = 2e9;
            int a = x + dx[d], b = y + dy[d];
            if (a < 0 || a >= m || b < 0 || b >= n || matrix[a][b] == 2e9) {
                d = (d + 1) % 4;
                a = x + dx[d], b = y + dy[d];
            }
            x = a, y = b;
        }
        return res;
    }
};
// @lc code=end
