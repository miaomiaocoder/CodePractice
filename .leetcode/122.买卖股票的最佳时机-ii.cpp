/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
// 把利润分解为每天为单位的维度
class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        for (int i = 0; i + 1 < prices.size(); i++)
            res += max(0, prices[i + 1] - prices[i]);
        return res;
    }
};

/*
f[i][0] 表示第i天持有股票所得现金。
f[i][1] 表示第i天不持有股票所得最多现金
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        vector<vector<int>> f(len, vector<int>(2, 0));
        f[0][0] -= prices[0];
        f[0][1] = 0;
        for (int i = 1; i < len; i++) {
            f[i][0] = max(f[i - 1][0], f[i - 1][1] - prices[i]); 
            f[i][1] = max(f[i - 1][1], f[i - 1][0] + prices[i]);
        }
        return f[len - 1][1];
    }
};
// @lc code=end
