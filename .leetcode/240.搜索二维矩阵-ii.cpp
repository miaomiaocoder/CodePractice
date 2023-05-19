/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start
class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int i = 0, j = n - 1;
        while (i < m && j >= 0) {
            if (target == matrix[i][j])
                return true;
            else if (target > matrix[i][j])
                ++i;
            else
                --j;
        }
        return false;
    }
};
// @lc code=end
