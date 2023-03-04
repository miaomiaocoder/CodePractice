/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */

// @lc code=start
/*
    没有操作
    第一次持有股票
    第一次不持有股票
    第二次持有股票
    第二次不持有股票
*/
class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        vector<vector<int>> f(len, vector<int>(5, 0));
        f[0][1] -= prices[0];
        f[0][3] -= prices[0];
        f[0][0] = f[0][2] = f[0][4] = 0;
        for (int i = 1; i < len; i++) {
            f[i][0] = f[i - 1][0];
            f[i][1] = max(f[i - 1][1], f[i - 1][0] - prices[i]);
            f[i][2] = max(f[i - 1][2], f[i - 1][1] + prices[i]);
            f[i][3] = max(f[i - 1][3], f[i - 1][2] - prices[i]);
            f[i][4] = max(f[i - 1][4], f[i - 1][3] + prices[i]);
        }
        return f[len - 1][4];
    }
};
// @lc code=end
