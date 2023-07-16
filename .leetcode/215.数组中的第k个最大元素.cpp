/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
// 注意是从大到小排序
class Solution {
    int quick_sort(vector<int>& nums, int l, int r, int k) {
        if (l == r) return nums[k];
        int x = nums[l + r >> 1], i = l - 1, j = r + 1;
        while (i < j) {
            do ++i;
            while (nums[i] > x);
            do --j;
            while (nums[j] < x);
            if (i < j) swap(nums[i], nums[j]);
        }
        if (k <= j)
            return quick_sort(nums, l, j, k);
        else
            return quick_sort(nums, j + 1, r, k);
    }

   public:
    int findKthLargest(vector<int>& nums, int k) {
        return quick_sort(nums, 0, nums.size() - 1, k - 1);
    }
};
// @lc code=end
