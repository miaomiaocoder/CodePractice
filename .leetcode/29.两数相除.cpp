/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */

// @lc code=start
class Solution {
   public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        if (dividend == INT_MIN && divisor == 1) return INT_MIN;
        if (dividend > 0) return -divide(-dividend, divisor);
        if (divisor > 0) return -divide(dividend, -divisor);
        if (dividend > divisor) return 0;
        int res = 1, tmp = divisor;
        while ((dividend - divisor) <= divisor) {
            res += res;
            divisor += divisor;
        }
        return res + divide(dividend - divisor, tmp);
    }
};
// @lc code=end
