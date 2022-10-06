/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
class Solution {
   public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = 2e9;
        for (int i = 0, j = 0, sum = 0; i < nums.size(); i++) {
            sum += nums[i];
            while (sum - nums[j] >= target) sum -= nums[j++];
            if (sum >= target) res = min(res, i - j + 1);
        }
        if (res == 2e9) return 0;
        return res;
    }
};
// @lc code=end
