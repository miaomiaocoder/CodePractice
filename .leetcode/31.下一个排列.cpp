/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

// @lc code=start
// https://programmercarl.com/0031.%E4%B8%8B%E4%B8%80%E4%B8%AA%E6%8E%92%E5%88%97.html
class Solution {
   public:
    void nextPermutation(vector<int>& nums) {
        for (int i = nums.size() - 1; i >= 0; i--) {
            for (int j = nums.size() - 1; j > i; j--) {
                if (nums[j] > nums[i]) {
                    swap(nums[j], nums[i]);
                    // 这时已经把nums[j]换过来了到了i的位置，只要让i + 1
                    // 之后保持有序即可
                    reverse(nums.begin() + i + 1, nums.end());
                    return;
                }
            }
        }
        // 到这里了说明整个数组都是倒序了，反转一下便可
        reverse(nums.begin(), nums.end());
    }
};
// @lc code=end
