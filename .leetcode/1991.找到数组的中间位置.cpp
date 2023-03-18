/*
 * @lc app=leetcode.cn id=1991 lang=cpp
 *
 * [1991] 找到数组的中间位置
 */

// @lc code=start
class Solution {
   public:
    int findMiddleIndex(vector<int>& nums) {
        int sum = 0;
        for (int& x : nums) {
            sum += x;
        }
        int leftSum = 0;
        int rightSum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            leftSum += nums[i];
            rightSum = sum + nums[i] - leftSum;
            if (leftSum == rightSum) return i;
        }
        return -1;
    }
};
// @lc code=end
