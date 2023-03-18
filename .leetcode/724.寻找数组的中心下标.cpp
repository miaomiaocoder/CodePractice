/*
 * @lc app=leetcode.cn id=724 lang=cpp
 *
 * [724] 寻找数组的中心下标
 */

// @lc code=start
class Solution {
   public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        for (int& num : nums) sum += num;
        int leftSum = 0;
        int rightSum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            leftSum += nums[i];
            rightSum = sum - leftSum + nums[i];
            if (leftSum == rightSum) return i;
        }
        return -1;
    }
};
// @lc code=end
