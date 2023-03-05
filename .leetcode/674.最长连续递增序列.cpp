/*
 * @lc app=leetcode.cn id=674 lang=cpp
 *
 * [674] 最长连续递增序列
 */

// @lc code=start
class Solution {
   public:
    int findLengthOfLCIS(vector<int>& nums) {
        int res = 1;
        vector<int> f(nums.size(), 1);
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) f[i] = f[i - 1] + 1;
            if (f[i] > res) res = f[i];
        }
        return res;
    }
};
// @lc code=end
