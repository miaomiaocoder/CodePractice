/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除有序数组中的重复项 II
 */

// @lc code=start
// nums[fast] 表示待检查的第一个元素，nums[slow−1]
// 为上一个应该被保留的元素所移动到的指定位置
class Solution {
   public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;
        int slow = 2, fast = 2;
        while (fast < n) {
            if (nums[slow - 2] != nums[fast]) {
                nums[slow] = nums[fast];
                ++slow;
            }
            ++fast;
        }
        return slow;
    }
};

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        for (auto x: nums) {
            if (k < 2 || nums[k - 2] != x)
                nums[k++] = x;
        }
        return k;
    }
};


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        for (auto x: nums) {
            if (k < 2 || nums[k - 1] != x || nums[k - 2] != x)
                nums[k++] = x;
        }
        return k;
    }
};
// @lc code=end
