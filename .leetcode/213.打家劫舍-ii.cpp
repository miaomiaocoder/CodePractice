/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
class Solution {
   public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        int val1 = robRange(nums, 0, nums.size() - 2);
        int val2 = robRange(nums, 1, nums.size() - 1);
        return max(val1, val2);
    }

    int robRange(vector<int>& nums, int l, int r) {
        if (l == r) return nums[l];
        vector<int> f(nums.size() + 1, 0);
        f[l] = nums[l];
        f[l + 1] = max(f[l], nums[l + 1]);
        for (int i = l + 2; i <= r; i++) {
            f[i] = max(f[i - 2] + nums[i], f[i - 1]);
        }
        return f[r];
    }
};
// @lc code=end
