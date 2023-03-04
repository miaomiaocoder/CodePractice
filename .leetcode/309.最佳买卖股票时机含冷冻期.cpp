/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 最佳买卖股票时机含冷冻期
 */

// @lc code=start
/*
    状态一：持有股票状态（今天买入股票，或者是之前就买入了股票然后没有操作，一直持有）
    不持有股票状态，这里就有两种卖出股票状态
        状态二：保持卖出股票的状态（两天前就卖出了股票，度过一天冷冻期。或者是前一天就是卖出股票状态，一直没操作）
        状态三：今天卖出股票
    状态四：今天为冷冻期状态，但冷冻期状态不可持续，只有一天！
*/
class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
        vector<vector<int>> f(n, vector<int>(4, 0));
        f[0][0] -= prices[0];
        for (int i = 1; i < n; i++) {
            f[i][0] = max(f[i - 1][0], max(f[i - 1][3] - prices[i],
                                           f[i - 1][1] - prices[i]));
            f[i][1] = max(f[i - 1][1], f[i - 1][3]);
            f[i][2] = f[i - 1][0] + prices[i];
            f[i][3] = f[i - 1][2];
        }
        return max(f[n - 1][3], max(f[n - 1][1], f[n - 1][2]));
    }
};
// @lc code=end
