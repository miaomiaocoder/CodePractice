/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
class Solution {
   public:
    int numSquares(int n) {
        vector<int> f(n + 1, INT_MAX);
        f[0] = 0;
        for (int i = 0; i <= n; i++)            // 遍历背包
            for (int j = 1; j * j <= i; j++) {  // 遍历物品
                f[i] = min(f[i - j * j] + 1, f[i]);
            }
        return f[n];
    }
};

class Solution {
   public:
    int numSquares(int n) {
        vector<int> f(n + 1, INT_MAX);
        f[0] = 0;
        for (int i = 1; i * i <= n; i++)    // 遍历物品
            for (int j = 1; j <= n; j++) {  // 遍历背包
                if (j - i * i >= 0) {
                    f[j] = min(f[j - i * i] + 1, f[j]);
                }
            }
        return f[n];
    }
};
// @lc code=end
