/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
// 注意[0, j - 1] 维护一个全是0的区间，[j, i - 1] 维护全是1的区间， [k + 1, n - 1]维护全是2的区间
// [i, k] 还没有放置
class Solution {
   public:
    void sortColors(vector<int>& nums) {
        for (int i = 0, j = 0, k = nums.size() - 1; i <= k;) {
            if (nums[i] == 0)
                swap(nums[i++], nums[j++]);
            else if (nums[i] == 2)
                swap(nums[i], nums[k--]);
            else
                i++;
        }
    }
};
// @lc code=end
