/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */

// @lc code=start
class Solution {
   public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();

        int c0 = 1, r0 = 1;
        for (int i = 0; i < m; ++i)
            if (!matrix[i][0]) c0 = 0;
        for (int j = 0; j < n; ++j)
            if (!matrix[0][j]) r0 = 0;

        for (int i = 1; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (!matrix[i][j]) matrix[i][0] = 0;

        for (int i = 1; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (!matrix[j][i]) matrix[0][i] = 0;

        for (int i = 1; i < m; ++i)
            if (!matrix[i][0])
                for (int j = 0; j < n; ++j) matrix[i][j] = 0;

        for (int i = 1; i < n; ++i)
            if (!matrix[0][i])
                for (int j = 0; j < m; ++j) matrix[j][i] = 0;

        if (!c0)
            for (int i = 0; i < m; ++i) matrix[i][0] = 0;
        if (!r0)
            for (int j = 0; j < n; ++j) matrix[0][j] = 0;
    }
};
// @lc code=end
