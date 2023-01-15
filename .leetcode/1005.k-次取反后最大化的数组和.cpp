/*
 * @lc app=leetcode.cn id=1005 lang=cpp
 *
 * [1005] K 次取反后最大化的数组和
 */

// @lc code=start
class Solution {
   public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(),
             [](int a, int b) { return abs(a) > abs(b); });  // 第一步

        for (int i = 0; i < nums.size(); i++) {  // 第二步
            if (nums[i] < 0 && k > 0) {
                nums[i] *= -1;
                k--;
            }
        }

        if (k % 2 == 1) nums[nums.size() - 1] *= -1;  // 第三步
        int res = 0;
        for (int x : nums) res += x;  // 第四步
        return res;
    }
};
// @lc code=end
