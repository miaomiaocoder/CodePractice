/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */

// @lc code=start
// 除了0以外，偶数就是卖出，奇数就是买入
class Solution {
   public:
    int maxProfit(int k, vector<int>& prices) {
        int len = prices.size();
        vector<vector<int>> f(len, vector<int>(2 * k + 1, 0));
        for (int j = 1; j < 2 * k; j += 2) {
            f[0][j] = -prices[0];
        }
        for (int i = 1; i < len; i++) {
            for (int j = 0; j < 2 * k; j += 2) {
                f[i][j + 1] = max(f[i - 1][j + 1], f[i - 1][j] - prices[i]);
                f[i][j + 2] = max(f[i - 1][j + 2], f[i - 1][j + 1] + prices[i]);
            }
        }
        return f[len - 1][2 * k];
    }
};
// @lc code=end
