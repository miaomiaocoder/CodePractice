/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
   public:
    int climbStairs(int n) {
        int a = 1, b = 1;
        while (--n) {
            int c = a + b;
            a = b, b = c;
        }
        return b;
    }
};

class Solution {
   public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        vector<int> dp(n + 1);
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

class Solution {
   public:
    int climbStairs(int n) {
        vector<int> f(n + 1, 1);
        f[0] = 1;
        f[1] = 1;
        for (int i = 2; i <= n; ++i) {
            f[i] = f[i - 1] + f[i - 2];
        }
        return f[n];
    }
};
// @lc code=end
