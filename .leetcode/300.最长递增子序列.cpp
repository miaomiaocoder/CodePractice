/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
class Solution {
   public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        vector<int> f(nums.size(), 1);
        int res = 0;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) f[i] = max(f[i], f[j] + 1);
            }
            if (f[i] > res) res = f[i];
        }
        return res;
    }
};
// @lc code=end
