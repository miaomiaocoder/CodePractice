/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */

// @lc code=start
class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);
        for (int i = 1; i < n; ++i) res[i] = res[i - 1] * nums[i - 1];
        for (int i = n - 1, s = 1; i >= 0; --i) {
            res[i] *= s;
            s *= nums[i];
        }
        return res;
    }
};
// @lc code=end
