/*
 * @lc app=leetcode.cn id=377 lang=cpp
 *
 * [377] 组合总和 Ⅳ
 */

// @lc code=start
class Solution {
   public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<long long> f(target + 1, 0);
        f[0] = 1;
        for (int i = 0; i <= target; ++i) {
            for (int num : nums) {
                if (i >= num && f[i] < INT_MAX - f[i - num]) {
                    f[i] += f[i - num];
                }
            }
        }
        return f[target];
    }
};

class Solution {
   public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<long long> f(target + 1, 0);
        f[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (int num : nums) {
                if (i >= num) f[i] = (f[i] + f[i - num]) % INT_MAX;
            }
        }
        return f[target];
    }
};

// @lc code=end
