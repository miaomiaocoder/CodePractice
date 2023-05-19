/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
class Solution {
   public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < i; ++j) swap(matrix[i][j], matrix[j][i]);
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0, k = n - 1; j < k; ++j, --k)
                swap(matrix[i][j], matrix[i][k]);
        }
    }
};
// @lc code=end
