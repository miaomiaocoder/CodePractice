/*
 * @lc app=leetcode.cn id=154 lang=cpp
 *
 * [154] 寻找旋转排序数组中的最小值 II
 */

// @lc code=start
class Solution {
   public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        // 最后一个数和第一个数相同，把最后一个数删掉
        while (l < r && nums[r] == nums[0]) r--;
        // 特判整个区间单调递增情况
        if (nums[l] <= nums[r]) return nums[0];
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] < nums[0])
                r = mid;
            else
                l = mid + 1;
        }
        return nums[r];
    }
};
// @lc code=end
