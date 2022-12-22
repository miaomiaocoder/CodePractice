/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN;
        for (int i = 0, last = 0; i < nums.size(); i++) {
            last = nums[i] + max(last, 0);
            res = max(last, res);
        }
        return res;
    }
};
// @lc code=end
