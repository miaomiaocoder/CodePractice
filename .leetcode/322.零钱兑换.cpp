/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
//  外层for循环遍历物品（钱币），内层for遍历背包（金钱总额）
class Solution {
   public:
    int coinChange(vector<int>& coins, int amount) {
        vector<long long> f(amount + 1, INT_MAX);
        f[0] = 0;
        for (int coin : coins) {
            for (int j = coin; j <= amount; j++)
                f[j] = min(f[j], f[j - coin] + 1);
        }
        if (f[amount] == INT_MAX) return -1;
        return f[amount];
    }
};

class Solution {
   public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> f(amount + 1, 2e9);
        f[0] = 0;
        for (int i = 0; i <= amount; ++i) {
            for (int j = 0; j < coins.size(); ++j) {
                if (coins[j] <= i) f[i] = min(f[i - coins[j]] + 1, f[i]);
            }
        }
        if (f[amount] == 2e9) return -1;
        return f[amount];
    }
};
// @lc code=end
