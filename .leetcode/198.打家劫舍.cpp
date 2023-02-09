/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
class Solution {
   public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        vector<int> f(nums.size() + 1, 0);
        f[0] = nums[0];
        f[1] = max(nums[1], f[0]);
        for (int i = 2; i < nums.size(); i++) {
            f[i] = max(f[i - 2] + nums[i], f[i - 1]);
        }
        return f[nums.size() - 1];
    }
};
// @lc code=end
