/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start
// 01背包问题
class Solution {
   public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int x : nums) sum += x;
        if (abs(target) > sum) return 0;
        if ((sum + target) % 2 == 1) return 0;
        int mid = (sum + target) / 2;
        vector<int> f(mid + 1, 0);
        f[0] = 1;
        for (int x : nums)
            for (int j = mid; j >= x; j--) f[j] += f[j - x];

        return f[mid];
    }
};
// @lc code=end
