/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
class Solution {
   public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        for (int i = 0; i < nums.size(); i++)
            if (!i || nums[i] != nums[i - 1]) nums[k++] = nums[i];
        return k;
    }
};
// @lc code=end
