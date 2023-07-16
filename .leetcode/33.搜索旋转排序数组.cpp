/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution {
   public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (nums[mid] >= nums[0])
                l = mid;
            else
                r = mid - 1;
        }

        if (target >= nums[0])
            l = 0;
        else
            l = r + 1, r = nums.size() - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] >= target)
                r = mid;
            else
                l = mid + 1;
        }
        // 注意这里如果使用 nums[l] 与 target 相比，nums只有一个元素
        // [1] 0的情况有问题，此时没有进入二分循环
        if (nums[r] == target) return r;
        return -1;
    }
};
// @lc code=end
