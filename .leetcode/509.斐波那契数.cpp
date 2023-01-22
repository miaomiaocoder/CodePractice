/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
class Solution {
   public:
    int fib(int n) {
        if (n < 2) return n;
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

class Solution {
   public:
    int fib(int n) {
        if (n < 2) return n;
        return fib(n - 1) + fib(n - 2);
    }
};

class Solution {
   public:
    int fib(int n) {
        if (n < 2) return n;
        int a = 0, b = 1;
        while (n--) {
            int c = a + b;
            a = b, b = c;
        }
        return a;
    }
};
// @lc code=end
