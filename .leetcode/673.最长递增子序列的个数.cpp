/*
 * @lc app=leetcode.cn id=673 lang=cpp
 *
 * [673] 最长递增子序列的个数
 */

// @lc code=start
class Solution {
   public:
    int findNumberOfLIS(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        vector<int> f(nums.size(), 1);
        vector<int> count(nums.size(), 1);
        int maxCount = 0;
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    if (f[j] + 1 > f[i]) {
                        f[i] = f[j] + 1;
                        count[i] = count[j];
                    } else if (f[j] + 1 == f[i]) {
                        count[i] += count[j];
                    }
                }
                if (f[i] > maxCount) maxCount = f[i];
            }
        }
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (maxCount == f[i]) res += count[i];
        }
        return res;
    }
};
// @lc code=end
