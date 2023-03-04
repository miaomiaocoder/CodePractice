/*
 * @lc app=leetcode.cn id=714 lang=cpp
 *
 * [714] 买卖股票的最佳时机含手续费
 */

// @lc code=start
class Solution {
   public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> f(n + 1, vector<int>(2, INT_MIN));
        f[0][0] = 0;
        int res = 0;
        for (int i = 1; i <= n; i++) {
            f[i][0] = max(f[i - 1][0], f[i - 1][1] + prices[i - 1]);
            f[i][1] = max(f[i - 1][1], f[i - 1][0] - prices[i - 1] - fee);
            res = max(res, f[i][0]);
        }
        return res;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int len = prices.size();
        vector<vector<int>> f(len, vector<int>(2, 0));
        f[0][0] -= prices[0];
        for (int i = 1; i < len; i++) {
            f[i][0] = max(f[i - 1][0], f[i - 1][1] - prices[i]);
            f[i][1] = max(f[i - 1][1], f[i - 1][0] + prices[i] - fee);
        }
        return max(f[len - 1][0], f[len - 1][1]);
    }
};
// @lc code=end
