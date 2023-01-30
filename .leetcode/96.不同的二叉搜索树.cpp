/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start
class Solution {
   public:
    int numTrees(int n) {
        vector<int> f(n + 1);
        f[0] = 1;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= i; j++) f[i] += f[j - 1] * f[i - j];
        return f[n];
    }
};
// @lc code=end
