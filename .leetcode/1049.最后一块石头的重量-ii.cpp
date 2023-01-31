/*
 * @lc app=leetcode.cn id=1049 lang=cpp
 *
 * [1049] 最后一块石头的重量 II
 */

// @lc code=start
class Solution {
   public:
    int lastStoneWeightII(vector<int>& stones) {
        vector<int> f(3000, 0);
        int sum = 0;
        for (int x : stones) sum += x;
        int target = sum / 2;
        for (int x : stones)
            for (int j = target; j >= x; j--) {
                f[j] = max(f[j], f[j - x] + x);
            }

        return sum - f[target] * 2;
    }
};
// @lc code=end
