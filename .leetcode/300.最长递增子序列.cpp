/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
// f[i]表示i之前包括i的以nums[i]结尾的最长递增子序列的长度
// 注意这里的定义，一定是以下标i为结尾，并不是说一定以下标0为起始位置。
class Solution {
   public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> f(nums.size(), 1);
        int res = 1;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) f[i] = max(f[i], f[j] + 1);
                if (f[i] > res) res = f[i];
            }
        }
        return res;
    }
};

class Solution {
   public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> f(nums.size(), 1);
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) f[i] = max(f[j] + 1, f[i]);
            }
            res = max(f[i], res);
        }
        return res;
    }
};
// @lc code=end
