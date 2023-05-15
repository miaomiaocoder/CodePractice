/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */

// @lc code=start
class Solution {
   public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int num : nums) {
            if (num <= 0) num = n + 1;
        }
        for (int i = 0; i < n; ++i) {
            int num = abs(nums[i]);
            if (num <= n) nums[num - 1] = -abs(nums[num - 1]);
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) return i + 1;
        }
        return n + 1;
    }
};
// @lc code=end
