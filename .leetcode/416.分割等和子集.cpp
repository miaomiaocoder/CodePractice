/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start
// 01背包问题
// f[j]表示 背包总容量（所能装的总重量）是j，放进物品后，背的最大重量为f[j]
class Solution {
   public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        for (int x : nums) sum += x;
        if (sum % 2 == 1) return false;
        int target = sum / 2;
        vector<int> f(target + 1, 0);

        for (int i = 0; i < n; i++)
            for (int j = target; j >= nums[i]; j--) {
                f[j] = max(f[j], f[j - nums[i]] + nums[i]);
            }

        if (f[target] == target) return true;
        return false;
    }
};
// @lc code=end
